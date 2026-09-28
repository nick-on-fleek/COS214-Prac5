#ifndef MEDICALINCIDENT_H
#define MEDICALINCIDENT_H

#include "Incident.h"

//  Fixed incident type (plain polymorphism, not itself a pattern) 
// State diagram: medical -> Dispatched; medical responders dispatched;
// no building-access change.
class MedicalIncident : public Incident {
public:
    MedicalIncident(std::string id, Mediator* m);
    std::string describe() const override;
    OperatorCommand* createDispatchCommand(IncidentCoordinator* coordinator) override;
    AccessStrategy* createAccessStrategy() const override;
    IncidentStatus* createNextStatusFromReported() const override;
};

#endif
