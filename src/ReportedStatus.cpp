#include "ReportedStatus.h"
#include "Incident.h"
#include <iostream>

void ReportedStatus::handle(Incident* i) {
    // Polymorphic branch (State diagram): medical/intruder -> Dispatched,
    // bomb threat -> Escalated. Incident subtype decides; no type-check here.
    std::cout << "[State] Incident " << i->getId() << ": Reported -> "
              << "(next status decided by incident type)." << std::endl;
    i->changeStatus(i->createNextStatusFromReported());
}

std::string ReportedStatus::getName() const {
    return "Reported";
}
