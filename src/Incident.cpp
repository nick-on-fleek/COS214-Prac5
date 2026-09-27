#include "Incident.h"

Incident::Incident(string id, Mediator m) {
	// TODO - implement Incident::Incident
	throw "Not yet implemented";
}

void Incident::ChangeStatus(IncidentStatus* s) {
	// TODO - implement Incident::ChangeStatus
	throw "Not yet implemented";
}

void Incident::advanceStatus() {
	// TODO - implement Incident::advanceStatus
	throw "Not yet implemented";
}

IncidentStatus* Incident::getStatus() {
	return this->status;
}

string Incident::getId() {
	return this->id;
}

void Incident::describe() {
	// TODO - implement Incident::describe
	throw "Not yet implemented";
}
