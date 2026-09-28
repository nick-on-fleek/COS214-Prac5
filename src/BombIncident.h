#ifndef BOMBINCIDENT_H
#define BOMBINCIDENT_H

#include "Incident.h"

//  Fixed incident type (plain polymorphism, not itself a pattern) 
// State diagram: bomb threat -> Escalated DIRECTLY (skips Dispatched);
// facilities staff dispatched; building access -> EvacuationStrategy.
class BombIncident : public Incident {
public:
    BombIncident(std::string id, Mediator* m);
    std::string describe() const override;
    OperatorCommand* createDispatchCommand(IncidentCoordinator* coordinator) override;
    AccessStrategy* createAccessStrategy() const override;
    IncidentStatus* createNextStatusFromReported() const override;
};

#endif
