#ifndef DISPATCHMEDICALRESPONDER_H
#define DISPATCHMEDICALRESPONDER_H

class DispatchMedicalResponder : OperatorCommand {

public:
	MedicalResponders* unit;

	void execute();

	DispatchMedicalResponder(MedicalResponders* u, Mediator* m);

	void undo();
};

#endif
