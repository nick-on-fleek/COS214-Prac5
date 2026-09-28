#ifndef MEDICALRESPONDERS_H
#define MEDICALRESPONDERS_H

#include <vector>
#include <string>
#include "People.h"

//  GoF Participant: ConcreteReceiver - Command pattern 
class MedicalResponders : public People {
public:
    std::vector<std::string> responders;

    MedicalResponders();
    void dispatch() override;
    void recall() override;
    void action() override;

private:
    bool dispatched;
};

#endif
