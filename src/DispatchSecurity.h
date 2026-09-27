#ifndef DISPATCHSECURITY_H
#define DISPATCHSECURITY_H

class DispatchSecurity : OperatorCommand {

public:
	SecurityUnit* unit;

	void execute();

	DispatchSecurity(SecurityUnit* u, Mediator* m);

	void undo();
};

#endif
