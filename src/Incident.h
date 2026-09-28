#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include "Colleague.h"
#include "IncidentStatus.h"

class IncidentCoordinator; // forward declaration
class OperatorCommand;     // forward declaration
class AccessStrategy;      // forward declaration

//  GoF Participant: Context (State pattern) + Colleague (Mediator pattern) 
// Incident's *type* (Medical/Bomb/Intruder) is fixed at construction and is
// plain polymorphism - the State pattern participant is the *status*
// lifecycle (see IncidentStatus and its concrete states).
//
// The three pure-virtual "create..." methods below let each incident type
// decide, polymorphically, which unit responds, which building strategy (if
// any) applies, and which status follows Reported - matching the team's
// state diagram (medical/intruder -> Dispatched, bomb -> Escalated) WITHOUT
// resorting to a type-check / switch on the incident's concrete class.
class Incident : public Colleague {
private:
    std::string id;
    IncidentStatus* status; // owned - deleted on reassignment and in destructor
public:
    Incident(std::string id, Mediator* m);

    void changeStatus(IncidentStatus* s);
    void advanceStatus();
    void escalate();

    IncidentStatus* getStatus() const;
    std::string getId() const;

    virtual std::string describe() const = 0;
    virtual OperatorCommand* createDispatchCommand(IncidentCoordinator* coordinator) = 0;
    virtual AccessStrategy* createAccessStrategy() const = 0; // may return nullptr
    virtual IncidentStatus* createNextStatusFromReported() const = 0;

    virtual ~Incident();
};

#endif
