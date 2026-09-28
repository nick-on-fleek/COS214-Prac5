#ifndef EVACUATIONSTRATEGY_H
#define EVACUATIONSTRATEGY_H

#include "AccessStrategy.h"

//  GoF Participant: ConcreteStrategy - Strategy pattern 
class EvacuationStrategy : public AccessStrategy {
public:
    void applyAccess(Building* b) override;
};

#endif
