#include "FullLockdownStrategy.h"
#include "Building.h"
#include <iostream>

void FullLockdownStrategy::applyAccess(Building* b) {
    b->setAccessState("Full Lockdown");
    std::cout << "[Strategy] " << b->getBuildingId()
              << " is now in FULL LOCKDOWN -- all entry points sealed." << std::endl;
}
