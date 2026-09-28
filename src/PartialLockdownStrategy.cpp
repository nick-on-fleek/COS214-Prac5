#include "PartialLockdownStrategy.h"
#include "Building.h"
#include <iostream>

void PartialLockdownStrategy::applyAccess(Building* b) {
    b->setAccessState("Partial Lockdown");
    std::cout << "[Strategy] " << b->getBuildingId()
              << " is now PARTIALLY RESTRICTED -- main entrance only." << std::endl;
}
