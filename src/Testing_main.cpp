#include <iostream>
#include "IncidentCoordinator.h"
#include "OperatorConsole.h"
#include "CampusGuardFacade.h"
#include "SecurityUnit.h"
#include "MedicalResponders.h"
#include "Staff.h"
#include "PaSystem.h"
#include "PaSystemAdapter.h"
#include "Building.h"
#include "MedicalIncident.h"
#include "BombIncident.h"
#include "IntruderIncident.h"
#include "EmergencyAlert.h"
#include "DispatchStaff.h"

// According to our spec rue 4:
//   - Incident owns its IncidentStatus*             (deleted on transition/destruction)
//   - Building owns its AccessStrategy*             (deleted on transition/destruction)
//   - OperatorConsole owns executed OperatorCommand* (history; deleted on cancel
//     or in its own destructor)
//   - PaSystemAdapter owns its PaSystem* adaptee     (deleted in its destructor)
//   - SecurityUnit / MedicalResponders / Staff / Building / IncidentCoordinator /
//     OperatorConsole / CampusGuardFacade are stack-allocated in main() and are
//     NOT owned by anything else that references them (Command receivers,
//     Mediator, Facade all hold *non-owning* pointers to them).

/*I tested with:

g++ -std=c++11 -Wall -Werror -g \
src/BombIncident.cpp \
src/Building.cpp \
src/BuildingAccess.cpp \
src/CampusGuardFacade.cpp \
src/Colleague.cpp \
src/DispatchedStatus.cpp \
src/DispatchMedicalResponder.cpp \
src/DispatchSecurity.cpp \
src/DispatchStaff.cpp \
src/EmergencyAlert.cpp \
src/EscalatedStatus.cpp \
src/EvacuationStrategy.cpp \
src/FullLockdownStrategy.cpp \
src/Incident.cpp \
src/IncidentCoordinator.cpp \
src/IntruderIncident.cpp \
src/MedicalIncident.cpp \
src/MedicalResponders.cpp \
src/OperatorCommand.cpp \
src/OperatorConsole.cpp \
src/PartialLockdownStrategy.cpp \
src/PaSystem.cpp \
src/PaSystemAdapter.cpp \
src/ReportedStatus.cpp \
src/ResolvedStatus.cpp \
src/SecurityUnit.cpp \
src/Staff.cpp \
src/Testing_main.cpp \
-o test

./test

*/


int main() {
    std::cout << "======" << std::endl;
    std::cout << " CampusGuard - Emergency Response Test" << std::endl;
    std::cout << "======" << std::endl;

    //  shared subsystem components 
    SecurityUnit security;
    MedicalResponders medical;
    Staff facilities;

    PaSystem* legacyPA = new PaSystem();                  // Adaptee
    CommsSystem* comms = new PaSystemAdapter(legacyPA);   // Adapter (used via the Target interface)

    Building mainBuilding("Student Union Building");

    IncidentCoordinator coordinator(&security, &medical, &facilities, comms); // ConcreteMediator

    OperatorConsole console;                                             // Invoker
    CampusGuardFacade facade(&console, &coordinator, comms, &mainBuilding); // Facade

    //  Invalid-operation case #1: cancel with nothing in history 
    std::cout << "\n--- Attempting to cancel before any command has been issued ---" << std::endl;
    console.cancelLastCommand();

    //  Scenario 1: Medical Incident 
    // State diagram path: Reported -> Dispatched -> Resolved.
    // No building-access change for a medical incident.
    std::cout << "\n########## SCENARIO 1: Medical Incident ##########" << std::endl;
    MedicalIncident incident1("INC-001", &coordinator);
    facade.handleIncident(&incident1);   // dispatch medical + alert + advance (Reported -> Dispatched)
    facade.resolveIncident(&incident1);  // advance (Dispatched -> Resolved) + partial reopen

    std::cout << "\n--- Attempting to advance an already-resolved incident ---" << std::endl;
    incident1.advanceStatus(); // Invalid-operation case #2 (State: ResolvedStatus)

    std::cout << "\n--- Demonstrating Command cancel/undo ---" << std::endl;
    console.issueCommand(new DispatchStaff(&facilities, &coordinator));
    console.cancelLastCommand(); // recalls facilities staff

    //  Scenario 2: Intruder Alert 
    // State diagram path: Reported -> Dispatched -> Resolved.
    // Security is dispatched AND the building goes into full lockdown.
    std::cout << "\n########## SCENARIO 2: Intruder Alert ##########" << std::endl;
    IntruderIncident incident2("INC-002", &coordinator);
    facade.handleIncident(&incident2);
    facade.resolveIncident(&incident2);

    //  Scenario 3: Bomb Threat 
    // State diagram path: Reported -> Escalated (skips Dispatched) -> Resolved.
    // Facilities staff dispatched AND the building goes into evacuation mode.
    std::cout << "\n########## SCENARIO 3: Bomb Threat ##########" << std::endl;
    BombIncident incident3("INC-003", &coordinator);
    facade.handleIncident(&incident3); // Reported -> Escalated directly
    facade.resolveIncident(&incident3); // Escalated -> Resolved

    //  Invalid-operation case #3: legacy PA system failure (empty message) 
    std::cout << "\n--- Attempting to broadcast an empty emergency message ---" << std::endl;
    console.issueCommand(new EmergencyAlert(comms, "", &coordinator));

    std::cout << "\n======" << std::endl;
    std::cout << " Demo complete." << std::endl;
    std::cout << "======" << std::endl;

    delete comms; // PaSystemAdapter's destructor deletes legacyPA in turn
    return 0;
}
