#ifndef ESCALATEDSTATUS_H
#define ESCALATEDSTATUS_H

class EscalatedStatus : IncidentStatus {


public:
	void handle(Incident* i);
};

#endif
