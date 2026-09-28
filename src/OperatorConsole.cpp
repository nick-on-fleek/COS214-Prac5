#include "OperatorConsole.h"
#include <iostream>

OperatorConsole::OperatorConsole() : pending(nullptr) {}

void OperatorConsole::setCommand(OperatorCommand* c) {
    pending = c;
}

void OperatorConsole::doCommand() {
    if (!pending) {
        std::cout << "[OperatorConsole] No command set to execute." << std::endl;
        return;
    }
    std::cout << "[OperatorConsole] Executing: " << pending->getDescription() << std::endl;
    pending->execute();
    history.push_back(pending);
    pending = nullptr;
}

void OperatorConsole::issueCommand(OperatorCommand* c) {
    setCommand(c);
    doCommand();
}

void OperatorConsole::cancelLastCommand() {
    if (history.empty()) {
        // Invalid-operation case: cancelling with nothing to cancel is
        // handled sensibly instead of crashing or doing nothing silently.
        std::cout << "[OperatorConsole] No action to cancel." << std::endl;
        return;
    }
    OperatorCommand* last = history.back();
    history.pop_back();
    std::cout << "[OperatorConsole] Cancelling: " << last->getDescription() << std::endl;
    last->undo();
    delete last;
}

OperatorConsole::~OperatorConsole() {
    for (size_t i = 0; i < history.size(); ++i) {
        delete history[i];
    }
}
