#include "EvacuationStrategy.h"
#include "Building.h"
#include <iostream>

void EvacuationStrategy::applyAccess(Building* b) {
    b->setAccessState("Evacuation Mode");
    std::cout << "[Strategy] " << b->getBuildingId()
              << " is now in EVACUATION MODE -- exits unlocked, alarms sounding." << std::endl;
}
