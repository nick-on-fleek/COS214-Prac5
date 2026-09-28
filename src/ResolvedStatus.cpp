#include "ResolvedStatus.h"
#include "Incident.h"
#include <iostream>

void ResolvedStatus::handle(Incident* i) {
    // Invalid-operation case: advancing an already-resolved incident is
    // handled sensibly (reported) instead of silently ignored or crashing.
    // (The state diagram's "another incident is reported -> Reported" edge
    // is a NEW Incident object starting fresh, not this object re-firing --
    // each concrete Incident subtype already begins life in ReportedStatus.)
    std::cout << "[State] Incident " << i->getId()
              << " is already Resolved -- no further action taken." << std::endl;
}

std::string ResolvedStatus::getName() const {
    return "Resolved";
}
