#ifndef DISPATCHEDSTATUS_H
#define DISPATCHEDSTATUS_H

#include "IncidentStatus.h"

//  GoF Participant: ConcreteState - State pattern 
class DispatchedStatus : public IncidentStatus {
public:
    void handle(Incident* i) override;
    std::string getName() const override;
};

#endif
