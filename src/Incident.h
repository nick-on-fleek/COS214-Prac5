#ifndef INCIDENT_H
#define INCIDENT_H

class Incident : Colleague {

private:
	string id;
	IncidentStatus* status;

public:
	Incident(string id, Mediator m);

	void ChangeStatus(IncidentStatus* s);

	void advanceStatus();

	IncidentStatus* getStatus();

	string getId();

	void describe();

	void ~Incident();
};

#endif
