#include "BombIncident.h"
#include "ReportedStatus.h"
#include "EscalatedStatus.h"
#include "DispatchStaff.h"
#include "EvacuationStrategy.h"
#include "IncidentCoordinator.h"

BombIncident::BombIncident(std::string id, Mediator* m) : Incident(id, m) {
    changeStatus(new ReportedStatus());
}

std::string BombIncident::describe() const {
    return "Bomb Threat [" + getId() + "]";
}

OperatorCommand* BombIncident::createDispatchCommand(IncidentCoordinator* coordinator) {
    return new DispatchStaff(coordinator->getFacilitiesStaff(), coordinator);
}

AccessStrategy* BombIncident::createAccessStrategy() const {
    return new EvacuationStrategy();
}

IncidentStatus* BombIncident::createNextStatusFromReported() const {
    return new EscalatedStatus(); // skips Dispatched entirely, per the state diagram
}
