#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

#include <vector>
#include "OperatorCommand.h"

//  GoF Participant: Invoker - Command pattern 
class OperatorConsole {
private:
    std::vector<OperatorCommand*> history; // owned -- executed commands, for undo + cleanup
    OperatorCommand* pending;              // staged between setCommand() and doCommand()
public:
    OperatorConsole();
    void setCommand(OperatorCommand* c);
    void doCommand();
    void issueCommand(OperatorCommand* c); // convenience: setCommand() + doCommand()
    void cancelLastCommand();
    ~OperatorConsole();
};

#endif
