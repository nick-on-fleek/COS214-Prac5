#include "DispatchSecurity.h"

DispatchSecurity::DispatchSecurity(SecurityUnit* u, Mediator* m)
    : OperatorCommand(m), unit(u) {}

void DispatchSecurity::execute() {
    unit->dispatch();
    // Command -> Mediator: report the dispatch so other components can coordinate.
    if (mediator) mediator->notify(nullptr, "securityDispatched");
}

void DispatchSecurity::undo() {
    unit->recall();
}

std::string DispatchSecurity::getDescription() const {
    return "Dispatch Security Unit";
}
