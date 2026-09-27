#ifndef OPERATORCONSOLE_H
#define OPERATORCONSOLE_H

class OperatorConsole {

private:
	vector<OperatorCommand> history;

public:
	void setCommand(OperatorCommand c);

	void doCommand();

	void cancelLastCommand();
};

#endif
