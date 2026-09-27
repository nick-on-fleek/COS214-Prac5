#ifndef STAFF_H
#define STAFF_H

class Staff : People {

public:
	vector<string> staffMembers;

	void dispatch();

	void action();

	void recall();
};

#endif
