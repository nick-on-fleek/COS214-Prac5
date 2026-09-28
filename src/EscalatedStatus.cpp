#include "EscalatedStatus.h"
#include "ResolvedStatus.h"
#include "Incident.h"
#include <iostream>

void EscalatedStatus::handle(Incident* i) {
    // State diagram: Escalated -> Resolved.
    std::cout << "[State] Incident " << i->getId() << ": Escalated -> Resolved." << std::endl;
    i->changeStatus(new ResolvedStatus());
}

std::string EscalatedStatus::getName() const {
    return "Escalated";
}
