#ifndef EMERGENCYALERT_H
#define EMERGENCYALERT_H

class EmergencyAlert : OperatorCommand {

private:
	CommsSystem* commsSystem;
	string msg;

public:
	void execute();

	void undo();

	EmergencyAlert(string msg);
};

#endif
