#include "MedicalResponders.h"
#include <iostream>

MedicalResponders::MedicalResponders() : dispatched(false) {}

void MedicalResponders::dispatch() {
    if (dispatched) {
        std::cout << "[MedicalResponders] Already dispatched." << std::endl;
        return;
    }
    dispatched = true;
    std::cout << "[MedicalResponders] Medical team dispatched to the scene." << std::endl;
}

void MedicalResponders::recall() {
    if (!dispatched) {
        std::cout << "[MedicalResponders] Not currently dispatched -- nothing to recall." << std::endl;
        return;
    }
    dispatched = false;
    std::cout << "[MedicalResponders] Medical team recalled to base." << std::endl;
}

void MedicalResponders::action() {
    std::cout << "[MedicalResponders] Standing by / treating casualties on-site." << std::endl;
}
