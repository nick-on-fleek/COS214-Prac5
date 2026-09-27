#ifndef BUILDINGACCESS_H
#define BUILDINGACCESS_H

class BuildingAccess : OperatorCommand {

public:
	Building* mainBuilding;

	void execute();

	void undo();
};

#endif
