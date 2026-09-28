#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include <string>
#include "People.h"

//  GoF Participant: ConcreteReceiver - Command pattern 
class Staff : public People {
public:
    std::vector<std::string> staffMembers;

    Staff();
    void dispatch() override;
    void recall() override;
    void action() override;

private:
    bool dispatched;
};

#endif
