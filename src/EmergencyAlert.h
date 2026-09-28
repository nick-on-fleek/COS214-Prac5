#ifndef EMERGENCYALERT_H
#define EMERGENCYALERT_H

#include <string>
#include "OperatorCommand.h"
#include "CommsSystem.h"

//  GoF Participant: ConcreteCommand - Command pattern 
class EmergencyAlert : public OperatorCommand {
private:
    CommsSystem* commsSystem; // Receiver - not owned; may be the Adapter
    std::string msg;
public:
    EmergencyAlert(CommsSystem* c, std::string msg, Mediator* m);
    void execute() override;
    void undo() override;
    std::string getDescription() const override;
};

#endif
