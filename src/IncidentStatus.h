#ifndef INCIDENTSTATUS_H
#define INCIDENTSTATUS_H

#include <string>

class Incident; // forward declaration

//  GoF Participant: State (abstract) - State pattern 
class IncidentStatus {
public:
    virtual void handle(Incident* i) = 0;
    virtual std::string getName() const = 0;
    virtual ~IncidentStatus() {}
};

#endif
