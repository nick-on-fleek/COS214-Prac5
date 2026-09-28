#include "EmergencyAlert.h"
#include <iostream>

EmergencyAlert::EmergencyAlert(CommsSystem* c, std::string msg, Mediator* m)
    : OperatorCommand(m), commsSystem(c), msg(msg) {}

void EmergencyAlert::execute() {
    commsSystem->sendAlert(msg);
}

void EmergencyAlert::undo() {
    std::cout << "[EmergencyAlert] Cannot retract an alert that has already been broadcast." << std::endl;
}

std::string EmergencyAlert::getDescription() const {
    return "Emergency Alert: " + msg;
}
