#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "OperatorConsole.h"
#include "IncidentCoordinator.h"
#include "CommsSystem.h"
#include "Building.h"
#include "Incident.h"

//  GoF Participant: Facade - Facade pattern 
// All four subsystems below stay independently public/usable in their own
// right; the Facade only adds two high-level, multi-step entry points.
class CampusGuardFacade {
private:
    OperatorConsole* console;         // not owned
    IncidentCoordinator* coordinator; // not owned
    CommsSystem* comms;               // not owned
    Building* mainBuilding;           // not owned
public:
    CampusGuardFacade(OperatorConsole* c, IncidentCoordinator* ic, CommsSystem* cs, Building* b);
    void handleIncident(Incident* incident);
    void resolveIncident(Incident* incident);
};

#endif
