#ifndef FULLLOCKDOWNSTRATEGY_H
#define FULLLOCKDOWNSTRATEGY_H

#include "AccessStrategy.h"

//  GoF Participant: ConcreteStrategy - Strategy pattern 
class FullLockdownStrategy : public AccessStrategy {
public:
    void applyAccess(Building* b) override;
};

#endif
