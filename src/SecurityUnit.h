#ifndef SECURITYUNIT_H
#define SECURITYUNIT_H

class SecurityUnit : People {

public:
	vector<string> security;

	void dispatch();

	void action();

	void recall();
};

#endif
