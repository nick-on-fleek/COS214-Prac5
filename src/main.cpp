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

int main() {
    std::cout << "CampusGuard starting..." << std::endl;

    
    return 0;
}
