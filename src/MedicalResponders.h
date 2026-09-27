#ifndef MEDICALRESPONDERS_H
#define MEDICALRESPONDERS_H

class MedicalResponders : People {

public:
	vector<string> responders;

	void dispatch();

	void action();

	void recall();
};

#endif
