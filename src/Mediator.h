#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

class Colleague; // forward declaration

//  GoF Participant: Mediator (interface) - Mediator pattern 
class Mediator {
public:
    virtual void notify(Colleague* sender, std::string event) = 0;
    virtual ~Mediator() {}
};

#endif
