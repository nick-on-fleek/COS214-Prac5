#include "CampusGuardFacade.h"
#include "BuildingAccess.h"
#include "EmergencyAlert.h"
#include "PartialLockdownStrategy.h"
#include <iostream>

CampusGuardFacade::CampusGuardFacade(OperatorConsole* c, IncidentCoordinator* ic, CommsSystem* cs, Building* b)
    : console(c), coordinator(ic), comms(cs), mainBuilding(b) {}

void CampusGuardFacade::handleIncident(Incident* incident) {
    std::cout << "\n===== CampusGuardFacade: handling " << incident->describe() << " =====" << std::endl;

    // Step 1: dispatch the *respective* unit for this incident type (Command + Receiver;
    // which unit is decided polymorphically by the Incident subtype, not a type-check here)
    console->issueCommand(incident->createDispatchCommand(coordinator));

    // Step 2: apply the *respective* building-access strategy, if this incident type needs one
    // (Command configuring the Strategy pattern's context)
    AccessStrategy* strategy = incident->createAccessStrategy();
    if (strategy) {
        console->issueCommand(new BuildingAccess(mainBuilding, strategy, coordinator));
    }

    // Step 3: broadcast an alert (Command -> Adapter -> legacy PA system)
    console->issueCommand(new EmergencyAlert(comms, "Emergency reported: " + incident->describe(), coordinator));

    // Step 4: advance the incident's status (State pattern; this is what fans out to
    // Dispatched or Escalated depending on incident type, and triggers Mediator coordination)
    incident->advanceStatus();
}

void CampusGuardFacade::resolveIncident(Incident* incident) {
    std::cout << "\n===== CampusGuardFacade: resolving " << incident->describe() << " =====" << std::endl;
    incident->advanceStatus(); // State: Dispatched -> Resolved, or Escalated -> Resolved
    console->issueCommand(new BuildingAccess(mainBuilding, new PartialLockdownStrategy(), coordinator));
}
