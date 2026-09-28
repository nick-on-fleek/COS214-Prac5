#ifndef DISPATCHSTAFF_H
#define DISPATCHSTAFF_H

#include "OperatorCommand.h"
#include "Staff.h"

//  GoF Participant: ConcreteCommand - Command pattern 
class DispatchStaff : public OperatorCommand {
public:
    Staff* unit; // Receiver - not owned

    DispatchStaff(Staff* u, Mediator* m);
    void execute() override;
    void undo() override;
    std::string getDescription() const override;
};

#endif
