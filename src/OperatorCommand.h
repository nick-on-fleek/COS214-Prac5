#ifndef OPERATORCOMMAND_H
#define OPERATORCOMMAND_H

class OperatorCommand {

private:
	Mediator* mediator;

public:
	void execute();

	OperatorCommand(Mediator* m);

	string getDescription();

	void ~OperatorCommand();

	void undo();
};

#endif
