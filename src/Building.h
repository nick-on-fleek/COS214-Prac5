#ifndef BUILDING_H
#define BUILDING_H

class Building {

private:
	string buildingID;
	AccessStrategy* accessStrat;
	string accessState;

public:
	Building(string ID);

	void setAccessStrategy(AccessStrategy* s);

	void executeAccessChange();

	string getAccessState();

	void setAccessState(string s);
};

#endif
