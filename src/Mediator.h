#ifndef MEDIATOR_H
#define MEDIATOR_H

class Mediator {


public:
	void notify(Colleague* sender, string event);

	void ~Mediator();
};

#endif
