#ifndef FAILER_H
#define FAILER_H

#include "DecoratorNode.h"

class Failer : public DecoratorNode   // The opposite of a Succeeder, always returning fail.  Note that this can be achieved also by using an Inverter and setting its child to a Succeeder.
{
private:
	virtual bool run() override 
	{ 
		getChild()->run();  return false; 
	}
};

#endif // !FAILER_H

