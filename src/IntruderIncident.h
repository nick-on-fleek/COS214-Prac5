#ifndef INTRUDERINCIDENT_H
#define INTRUDERINCIDENT_H

#include "Incident.h"

//  Fixed incident type (plain polymorphism, not itself a pattern) 
// State diagram: intruder -> Dispatched; security dispatched;
// building access -> FullLockdownStrategy.
class IntruderIncident : public Incident {
public:
    IntruderIncident(std::string id, Mediator* m);
    std::string describe() const override;
    OperatorCommand* createDispatchCommand(IncidentCoordinator* coordinator) override;
    AccessStrategy* createAccessStrategy() const override;
    IncidentStatus* createNextStatusFromReported() const override;
};

#endif
