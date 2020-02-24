#ifndef SUCCEEDER_H
#define SUCCEEDER_H

#include "DecoratorNode.h"

class Succeeder : public DecoratorNode   // A succeeder will always return success, irrespective of what the child node actually returned. These are useful in cases where you want to process a branch of a tree where a failure is expected or anticipated, but you don’t want to abandon processing of a sequence that branch sits on.
{
private:
	virtual bool run() override 
	{ 
		getChild()->run();  return true; 
	}
};

#endif // !SUCCEEDER_H

