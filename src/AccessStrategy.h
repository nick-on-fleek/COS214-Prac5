#ifndef ACCESSSTRATEGY_H
#define ACCESSSTRATEGY_H

class Building; // forward declaration

//  GoF Participant: Strategy (abstract) - Strategy pattern 
class AccessStrategy {
public:
    virtual void applyAccess(Building* b) = 0;
    virtual ~AccessStrategy() {}
};

#endif
