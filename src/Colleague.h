#ifndef COLLEAGUE_H
#define COLLEAGUE_H

class Colleague {

private:
	Mediator mediator;

public:
	void setMediator(Mediator* m);

	void changed(string event);

	void ~Colleague();
};

#endif
