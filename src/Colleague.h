#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>
#include "Mediator.h"

//  GoF Participant: Colleague (abstract) - Mediator pattern 
class Colleague {
protected:
    Mediator* mediator; // not owned - mediator outlives colleagues here
public:
    explicit Colleague(Mediator* m);
    void setMediator(Mediator* m);
    void changed(const std::string& event); // tells the mediator something happened
    virtual ~Colleague();
};

#endif
