#include "DispatchMedicalResponder.h"

DispatchMedicalResponder::DispatchMedicalResponder(MedicalResponders* u, Mediator* m)
    : OperatorCommand(m), unit(u) {}

void DispatchMedicalResponder::execute() {
    unit->dispatch();
    if (mediator) mediator->notify(nullptr, "medicalDispatched");
}

void DispatchMedicalResponder::undo() {
    unit->recall();
}

std::string DispatchMedicalResponder::getDescription() const {
    return "Dispatch Medical Responders";
}
