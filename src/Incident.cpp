#include "Incident.h"
#include "EscalatedStatus.h"
#include <iostream>

Incident::Incident(std::string id, Mediator* m)
    : Colleague(m), id(id), status(nullptr) {}

void Incident::changeStatus(IncidentStatus* s) {
    delete status;
    status = s;
    changed("statusChanged"); // Colleague -> Mediator: lets other components coordinate
}

void Incident::advanceStatus() {
    if (status) {
        status->handle(this);
    }
}

void Incident::escalate() {
    std::cout << "[Incident] " << id << " has been escalated by an operator." << std::endl;
    changeStatus(new EscalatedStatus());
}

IncidentStatus* Incident::getStatus() const {
    return this->status;
}

std::string Incident::getId() const {
    return this->id;
}

Incident::~Incident() {
    delete status;
}
