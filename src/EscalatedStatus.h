#ifndef ESCALATEDSTATUS_H
#define ESCALATEDSTATUS_H

#include "IncidentStatus.h"

//  GoF Participant: ConcreteState - State pattern 
class EscalatedStatus : public IncidentStatus {
public:
    void handle(Incident* i) override;
    std::string getName() const override;
};

#endif
