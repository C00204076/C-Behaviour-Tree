#ifndef INVERTER_H
#define INVERTER_H

#include "DecoratorNode.h"

class Inverter : public DecoratorNode   // Inverts the result of the child. A child fails and it will return success to its parent, or a child succeeds and it will return failure to the parent.
{
private:
	virtual bool run() override 
	{ 
		return !getChild()->run(); 
	}
};

#endif // !INVERTER_H

