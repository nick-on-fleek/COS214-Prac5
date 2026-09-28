#ifndef BUILDINGACCESS_H
#define BUILDINGACCESS_H

#include "OperatorCommand.h"
#include "Building.h"
#include "AccessStrategy.h"

//  GoF Participant: ConcreteCommand - Command pattern.
//      Also the bridge into the Strategy pattern: it hands the Building
//      (Strategy-context) the AccessStrategy it should apply. 
class BuildingAccess : public OperatorCommand {
public:
    Building* mainBuilding; // Receiver -- not owned

    BuildingAccess(Building* b, AccessStrategy* s, Mediator* m);
    void execute() override;
    void undo() override;
    std::string getDescription() const override;

private:
    AccessStrategy* strategy; // ownership transferred to Building on execute()
};

#endif
