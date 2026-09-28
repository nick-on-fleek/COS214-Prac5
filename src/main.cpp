#include <iostream>

#include "ReportedStatus.h"
#include "EscalatedStatus.h"
#include "DispatchedStatus.h"
#include "ResolvedStatus.h"

#include "MedicalIncident.h"
#include "BombIncident.h"
#include "IntruderIncident.h"

#include "Colleague.h"
#include "Mediator.h"
#include "IncidentCoordinator.h"

#include "CampusGuardFacade.h"

#include "OperatorCommand.h"
#include "OperatorConsole.h"
#include "BuildingAccess.h"
#include "DispatchSecurity.h"
#include "DispatchMedicalResponder.h"
#include "DispatchStaff.h"
#include "EmergencyAlert.h"

#include "Building.h"
#include "AccessStrategy.h"
#include "FullLockdownStrategy.h"
#include "PartialLockdownStrategy.h"
#include "EvacuationStrategy.h"

#include "Staff.h"
#include "MedicalResponders.h"
#include "SecurityUnit.h"

#include "CommsSystem.h"
#include "PaSystem.h"
#include "PaSystemAdapter.h"

using namespace std;

int main() {
    cout << ">" << endl;

    Staff staff;
    MedicalResponders medRes;
    SecurityUnit secUnit;

    PaSystem* oldPA = new PaSystem(); 
    CommsSystem* commSystem = new PaSystemAdapter(oldPA);

    Building lawLibrary("Law Library");

    IncidentCoordinator coordinators(&secUnit, &medRes, &staff, commSystem);

    OperatorConsole console;

    cout << "Scenario 1" << endl;
    cout << "Bomb threat is reported inside UP's Law Library. Emergency exits are opened and alarms go off. Students are notified from communications (and old PA) system to leave the building. Staff help evacuate the students and security watch the area" << endl << endl;

    BombIncident bomb("Bomb Threat Incident", &coordinators);

    // Can swap out with facade - but using a difference sequence to handle it for the scenario.

    AccessStrategy* strategy = bomb.createAccessStrategy();

    bomb.advanceStatus();

    console.issueCommand(new BuildingAccess(&lawLibrary, strategy, &coordinators));
    console.issueCommand(new EmergencyAlert(commSystem, "All students to please evacuate the Law Library", &coordinators));
    console.issueCommand(bomb.createDispatchCommand(&coordinators));
    
    cout << endl << "The following would be by the University's protocol | for example | Police/Bomb Squad called, then they check the library" << endl;
    cout << "Bomb threat was a false alarm (no bomb was found)" << endl;

    CampusGuardFacade cgf(&console, &coordinators, commSystem, &lawLibrary);

    cgf.resolveIncident(&bomb);

    cout << endl;

    commSystem->sendAlert("Students can now return to the Law Library");

    delete commSystem;
    // delete strategy
    // delete cgf;

    cout << "<" << endl;

    return 0;
}
