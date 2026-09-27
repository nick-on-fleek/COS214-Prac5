#ifndef DISPATCHSTAFF_H
#define DISPATCHSTAFF_H

class DispatchStaff : OperatorCommand {

public:
	Staff* unit;

	void execute();

	DispatchStaff(Staff* u, Mediator* m);

	void undo();
};

#endif
