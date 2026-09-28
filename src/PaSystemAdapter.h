#ifndef PASYSTEMADAPTER_H
#define PASYSTEMADAPTER_H

#include "CommsSystem.h"
#include "PaSystem.h"

//  GoF Participant: Adapter - Adapter pattern 
class PaSystemAdapter : public CommsSystem {
public:
    PaSystem* adaptee; // owned - deleted in destructor

    explicit PaSystemAdapter(PaSystem* legacy);
    void sendAlert(std::string m) override;
    ~PaSystemAdapter();
};

#endif
