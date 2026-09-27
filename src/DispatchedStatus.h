#ifndef DISPATCHEDSTATUS_H
#define DISPATCHEDSTATUS_H

class DispatchedStatus : IncidentStatus {


public:
	void handle(Incident* i);
};

#endif
