#ifndef DISPATCHMEDICALRESPONDER_H
#define DISPATCHMEDICALRESPONDER_H

#include "OperatorCommand.h"
#include "MedicalResponders.h"

//  GoF Participant: ConcreteCommand - Command pattern 
class DispatchMedicalResponder : public OperatorCommand {
public:
    MedicalResponders* unit; // Receiver - not owned

    DispatchMedicalResponder(MedicalResponders* u, Mediator* m);
    void execute() override;
    void undo() override;
    std::string getDescription() const override;
};

#endif
