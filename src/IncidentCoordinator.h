#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

class IncidentCoordinator : Mediator {

private:
	Colleague* colleagues;
	SecurityUnit* security;
	MedicalResponders* medical;
	Staff* facilitiesStaff;
	CommsSystem* comms;

public:
	void notify(Colleague* sender, string event);

	IncidentCoordinator(SecurityUnit* s, MedicalResponders* m, Staff* f, CommsSystem* c);
};

#endif
