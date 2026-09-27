#ifndef COMMSSYSTEM_H
#define COMMSSYSTEM_H

class CommsSystem {

private:
	string currentMessage;

public:
	void sendAlert(string m);

	void ~CommsSystem();
};

#endif
