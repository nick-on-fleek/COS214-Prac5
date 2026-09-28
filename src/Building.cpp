#include "Building.h"
#include <iostream>

Building::Building(std::string ID) : buildingID(ID), accessStrat(nullptr), accessState("Normal") {}

void Building::setAccessStrategy(AccessStrategy* s) {
    delete accessStrat;
    accessStrat = s;
}

void Building::executeAccessChange() {
    if (!accessStrat) {
        std::cout << "[Building] No access strategy set for " << buildingID
                  << " -- cannot change access." << std::endl;
        return;
    }
    accessStrat->applyAccess(this);
}

std::string Building::getAccessState() {
    return this->accessState;
}

void Building::setAccessState(std::string s) {
    this->accessState = s;
}

std::string Building::getBuildingId() const {
    return buildingID;
}

Building::~Building() {
    delete accessStrat;
}
