#ifndef OPERATORCOMMAND_H
#define OPERATORCOMMAND_H

#include <string>
#include "Mediator.h"

//  GoF Participant: Command (abstract) - Command pattern 
class OperatorCommand {
protected:
    Mediator* mediator; // not owned
public:
    explicit OperatorCommand(Mediator* m);
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::string getDescription() const = 0;
    virtual ~OperatorCommand() {}
};

#endif
