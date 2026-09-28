#include "IntruderIncident.h"
#include "ReportedStatus.h"
#include "DispatchedStatus.h"
#include "DispatchSecurity.h"
#include "FullLockdownStrategy.h"
#include "IncidentCoordinator.h"

IntruderIncident::IntruderIncident(std::string id, Mediator* m) : Incident(id, m) {
    changeStatus(new ReportedStatus());
}

std::string IntruderIncident::describe() const {
    return "Intruder Alert [" + getId() + "]";
}

OperatorCommand* IntruderIncident::createDispatchCommand(IncidentCoordinator* coordinator) {
    return new DispatchSecurity(coordinator->getSecurityUnit(), coordinator);
}

AccessStrategy* IntruderIncident::createAccessStrategy() const {
    return new FullLockdownStrategy();
}

IncidentStatus* IntruderIncident::createNextStatusFromReported() const {
    return new DispatchedStatus();
}
