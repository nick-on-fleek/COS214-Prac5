#include "IncidentCoordinator.h"
#include "Incident.h"
#include <iostream>

IncidentCoordinator::IncidentCoordinator(SecurityUnit* s, MedicalResponders* m, Staff* f, CommsSystem* c)
    : colleagues(nullptr), security(s), medical(m), facilitiesStaff(f), comms(c) {}

void IncidentCoordinator::notify(Colleague* sender, std::string event) {
    colleagues = sender; // bookkeeping: remember the last colleague to report in

    if (event == "statusChanged") {
        // Command (via Incident::changeStatus) -> Colleague::changed() -> here.
        // This is the "one colleague's change coordinates the others" requirement.
        Incident* incident = dynamic_cast<Incident*>(sender);
        if (!incident || !incident->getStatus()) return;

        std::string statusName = incident->getStatus()->getName();
        std::cout << "[Mediator] Incident " << incident->getId()
                  << " is now " << statusName << "." << std::endl;

        if (statusName == "Dispatched") {
            std::cout << "[Mediator] Coordinating: response units are on scene for incident "
                      << incident->getId() << "." << std::endl;
        } else if (statusName == "Escalated") {
            std::cout << "[Mediator] Coordinating: escalation protocol engaged for incident "
                      << incident->getId() << " -- all units remain on high alert." << std::endl;
        } else if (statusName == "Resolved") {
            std::cout << "[Mediator] Incident " << incident->getId() << " closed out -- stand down." << std::endl;
        }
    } else if (event == "securityDispatched") {
        // A Command (DispatchSecurity) triggered this -- the mediator coordinates
        // a second colleague (medical) in response.
        std::cout << "[Mediator] Security dispatch acknowledged -- placing medical team on stand-by." << std::endl;
        if (medical) medical->action();
    } else if (event == "medicalDispatched") {
        std::cout << "[Mediator] Medical dispatch acknowledged." << std::endl;
    } else if (event == "staffDispatched") {
        std::cout << "[Mediator] Facilities staff dispatch acknowledged -- coordinating evacuation support." << std::endl;
        if (security) security->action();
    }
}

SecurityUnit* IncidentCoordinator::getSecurityUnit() const { return security; }
MedicalResponders* IncidentCoordinator::getMedicalResponders() const { return medical; }
Staff* IncidentCoordinator::getFacilitiesStaff() const { return facilitiesStaff; }
