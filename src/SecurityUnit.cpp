#include "SecurityUnit.h"
#include <iostream>

SecurityUnit::SecurityUnit() : dispatched(false) {}

void SecurityUnit::dispatch() {
    if (dispatched) {
        std::cout << "[SecurityUnit] Already dispatched." << std::endl;
        return;
    }
    dispatched = true;
    std::cout << "[SecurityUnit] Security officers dispatched to the scene." << std::endl;
}

void SecurityUnit::recall() {
    if (!dispatched) {
        std::cout << "[SecurityUnit] Not currently dispatched -- nothing to recall." << std::endl;
        return;
    }
    dispatched = false;
    std::cout << "[SecurityUnit] Security officers recalled to base." << std::endl;
}

void SecurityUnit::action() {
    std::cout << "[SecurityUnit] Securing perimeter and controlling access." << std::endl;
}
