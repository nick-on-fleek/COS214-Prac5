#ifndef DISPATCHSECURITY_H
#define DISPATCHSECURITY_H

#include "OperatorCommand.h"
#include "SecurityUnit.h"

//  GoF Participant: ConcreteCommand - Command pattern 
class DispatchSecurity : public OperatorCommand {
public:
    SecurityUnit* unit; // Receiver - not owned

    DispatchSecurity(SecurityUnit* u, Mediator* m);
    void execute() override;
    void undo() override;
    std::string getDescription() const override;
};

#endif
