#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

class CampusGuardFacade {

private:
	OperatorConsole* console;
	IncidentCoordinator* coordinator;
	CommsSystem* comms;
	Building* mainBuilding;

public:
	CampusGuardFacade(OperatorConsole* c, IncidentCoordinator* ic, CommsSystem* cs, Building* b);

	void handleIncident(Incident* incident);

	void resolveIncident(Incident* incident);
};

#endif
