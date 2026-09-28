#ifndef PEOPLE_H
#define PEOPLE_H

//  GoF Participant: Receiver (abstract) - Command pattern 
class People {
public:
    virtual void dispatch() = 0;
    virtual void recall() = 0;
    virtual void action() = 0;
    virtual ~People() {}
};

#endif
