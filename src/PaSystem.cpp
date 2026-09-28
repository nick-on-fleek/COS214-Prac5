#include "PaSystem.h"
#include <cstring>
#include <iostream>

int PaSystem::broadcast(const char* message, int priorityCode) {
    if (message == nullptr || std::strlen(message) == 0) {
        return -1; // legacy failure code: nothing to broadcast
    }
    std::cout << "[Legacy PA System] Broadcasting (priority " << priorityCode
              << "): " << message << std::endl;
    return 0;
}
