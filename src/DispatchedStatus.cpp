#include "DispatchedStatus.h"
#include "ResolvedStatus.h"
#include "Incident.h"
#include <iostream>

void DispatchedStatus::handle(Incident* i) {
    // State diagram: Dispatched -> Resolved.
    std::cout << "[State] Incident " << i->getId() << ": Dispatched -> Resolved." << std::endl;
    i->changeStatus(new ResolvedStatus());
}

std::string DispatchedStatus::getName() const {
    return "Dispatched";
}
