#ifndef REPORTEDSTATUS_H
#define REPORTEDSTATUS_H

#include "IncidentStatus.h"

//  GoF Participant: ConcreteState - State pattern 
class ReportedStatus : public IncidentStatus {
public:
    void handle(Incident* i) override;
    std::string getName() const override;
};

#endif
