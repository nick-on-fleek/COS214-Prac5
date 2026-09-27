#ifndef PASYSTEMADAPTER_H
#define PASYSTEMADAPTER_H

class PaSystemAdapter : CommsSystem {

public:
	PaSystem* adaptee;

	void sendAlert(string m);

	PaSystemAdapter(PaSystem* legacy);
};

#endif
