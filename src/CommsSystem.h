#ifndef COMMSSYSTEM_H
#define COMMSSYSTEM_H

#include <string>

//  GoF Participant: Target (interface) - Adapter pattern 
class CommsSystem {
protected:
    std::string currentMessage;
public:
    virtual void sendAlert(std::string m) = 0;
    virtual ~CommsSystem() {}
};

#endif
