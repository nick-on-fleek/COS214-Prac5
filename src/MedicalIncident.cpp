#include "MedicalIncident.h"
#include "ReportedStatus.h"
#include "DispatchedStatus.h"
#include "DispatchMedicalResponder.h"
#include "IncidentCoordinator.h"

MedicalIncident::MedicalIncident(std::string id, Mediator* m) : Incident(id, m) {
    changeStatus(new ReportedStatus());
}

std::string MedicalIncident::describe() const {
    return "Medical Incident [" + getId() + "]";
}

OperatorCommand* MedicalIncident::createDispatchCommand(IncidentCoordinator* coordinator) {
    return new DispatchMedicalResponder(coordinator->getMedicalResponders(), coordinator);
}

AccessStrategy* MedicalIncident::createAccessStrategy() const {
    return nullptr; // medical incidents do not change building access
}

IncidentStatus* MedicalIncident::createNextStatusFromReported() const {
    return new DispatchedStatus();
}
