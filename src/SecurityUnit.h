#ifndef SECURITYUNIT_H
#define SECURITYUNIT_H

#include <vector>
#include <string>
#include "People.h"

//  GoF Participant: ConcreteReceiver - Command pattern 
class SecurityUnit : public People {
public:
    std::vector<std::string> security;

    SecurityUnit();
    void dispatch() override;
    void recall() override;
    void action() override;

private:
    bool dispatched;
};

#endif
