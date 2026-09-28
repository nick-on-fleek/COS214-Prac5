#include "Staff.h"
#include <iostream>

Staff::Staff() : dispatched(false) {}

void Staff::dispatch() {
    if (dispatched) {
        std::cout << "[Staff] Facilities staff already dispatched." << std::endl;
        return;
    }
    dispatched = true;
    std::cout << "[Staff] Facilities staff dispatched to the scene." << std::endl;
}

void Staff::recall() {
    if (!dispatched) {
        std::cout << "[Staff] Not currently dispatched -- nothing to recall." << std::endl;
        return;
    }
    dispatched = false;
    std::cout << "[Staff] Facilities staff recalled to base." << std::endl;
}

void Staff::action() {
    std::cout << "[Staff] Assisting with building access and evacuation routes." << std::endl;
}
