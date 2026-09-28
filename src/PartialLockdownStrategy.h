#ifndef PARTIALLOCKDOWNSTRATEGY_H
#define PARTIALLOCKDOWNSTRATEGY_H

#include "AccessStrategy.h"

//  GoF Participant: ConcreteStrategy - Strategy pattern 
class PartialLockdownStrategy : public AccessStrategy {
public:
    void applyAccess(Building* b) override;
};

#endif
