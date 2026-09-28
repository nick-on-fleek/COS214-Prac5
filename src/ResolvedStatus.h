#ifndef RESOLVEDSTATUS_H
#define RESOLVEDSTATUS_H

#include "IncidentStatus.h"

//  GoF Participant: ConcreteState - State pattern 
class ResolvedStatus : public IncidentStatus {
public:
    void handle(Incident* i) override;
    std::string getName() const override;
};

#endif
