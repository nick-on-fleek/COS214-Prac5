#include "BuildingAccess.h"
#include "PartialLockdownStrategy.h"
#include <iostream>

BuildingAccess::BuildingAccess(Building* b, AccessStrategy* s, Mediator* m)
    : OperatorCommand(m), mainBuilding(b), strategy(s) {}

void BuildingAccess::execute() {
    mainBuilding->setAccessStrategy(strategy); // Building takes ownership from here
    mainBuilding->executeAccessChange();
}

void BuildingAccess::undo() {
    std::cout << "[BuildingAccess] Reverting " << mainBuilding->getBuildingId()
              << " to a partial-access state." << std::endl;
    mainBuilding->setAccessStrategy(new PartialLockdownStrategy());
    mainBuilding->executeAccessChange();
}

std::string BuildingAccess::getDescription() const {
    return "Change Building Access (" + mainBuilding->getBuildingId() + ")";
}
