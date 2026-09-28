#include "DispatchStaff.h"

DispatchStaff::DispatchStaff(Staff* u, Mediator* m)
    : OperatorCommand(m), unit(u) {}

void DispatchStaff::execute() {
    unit->dispatch();
    if (mediator) mediator->notify(nullptr, "staffDispatched");
}

void DispatchStaff::undo() {
    unit->recall();
}

std::string DispatchStaff::getDescription() const {
    return "Dispatch Facilities Staff";
}
