#include "Building.h"

Building::Building(string ID) {
	// TODO - implement Building::Building
	throw "Not yet implemented";
}

void Building::setAccessStrategy(AccessStrategy* s) {
	// TODO - implement Building::setAccessStrategy
	throw "Not yet implemented";
}

void Building::executeAccessChange() {
	// TODO - implement Building::executeAccessChange
	throw "Not yet implemented";
}

string Building::getAccessState() {
	return this->accessState;
}

void Building::setAccessState(string s) {
	this->accessState = s;
}
