#include "PaSystemAdapter.h"
#include <iostream>

PaSystemAdapter::PaSystemAdapter(PaSystem* legacy) : adaptee(legacy) {}

void PaSystemAdapter::sendAlert(std::string m) {
    currentMessage = m;
    int result = adaptee->broadcast(m.c_str(), 1); // priority 1 = emergency
    if (result != 0) {
        // Invalid-operation case: legacy system failed to broadcast -- handled
        // sensibly rather than silently ignored or crashing.
        std::cout << "[PaSystemAdapter] Legacy PA system failed to broadcast the alert." << std::endl;
    }
}

PaSystemAdapter::~PaSystemAdapter() {
    delete adaptee;
}
