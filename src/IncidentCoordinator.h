#ifndef INCIDENTCOORDINATOR_H
#define INCIDENTCOORDINATOR_H

#include <string>
#include "Mediator.h"
#include "Colleague.h"
#include "SecurityUnit.h"
#include "MedicalResponders.h"
#include "Staff.h"
#include "CommsSystem.h"

//  GoF Participant: ConcreteMediator - Mediator pattern 
class IncidentCoordinator : public Mediator {
private:
    Colleague* colleagues;      // last colleague seen (bookkeeping) - not owned
    SecurityUnit* security;     // not owned
    MedicalResponders* medical; // not owned
    Staff* facilitiesStaff;     // not owned
    CommsSystem* comms;         // not owned (may be the PaSystemAdapter)
public:
    IncidentCoordinator(SecurityUnit* s, MedicalResponders* m, Staff* f, CommsSystem* c);
    void notify(Colleague* sender, std::string event) override;

    // convenience accessors so callers (e.g. CampusGuardFacade, Incident
    // subtypes) can build Commands against the same shared receivers
    SecurityUnit* getSecurityUnit() const;
    MedicalResponders* getMedicalResponders() const;
    Staff* getFacilitiesStaff() const;
};

#endif
