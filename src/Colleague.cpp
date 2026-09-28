#include "Colleague.h"

Colleague::Colleague(Mediator* m) : mediator(m) {}

void Colleague::setMediator(Mediator* m) {
    mediator = m;
}

void Colleague::changed(const std::string& event) {
    if (mediator) {
        mediator->notify(this, event);
    }
}

Colleague::~Colleague() {}
