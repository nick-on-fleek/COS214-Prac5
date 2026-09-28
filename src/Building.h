#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "AccessStrategy.h"

//  GoF Participant: Context (Strategy pattern); Receiver for BuildingAccess (Command pattern) 
class Building {
private:
    std::string buildingID;
    AccessStrategy* accessStrat; // owned - deleted on reassignment and in destructor
    std::string accessState;
public:
    explicit Building(std::string ID);
    void setAccessStrategy(AccessStrategy* s);
    void executeAccessChange();
    std::string getAccessState();
    void setAccessState(std::string s);
    std::string getBuildingId() const;
    ~Building();
};

#endif
