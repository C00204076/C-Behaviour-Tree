#ifndef REPEATUNTILFAIL_H
#define REPEATUNTILFAIL_H

#include "DecoratorNode.h"

class RepeatUntilFail : public DecoratorNode   // Like a repeater, these decorators will continue to reprocess their child. That is until the child finally returns a failure, at which point the repeater will return success to its parent.
{
private:
	virtual bool run() override 
	{
		while (getChild()->run()) 
		{

		}
		return true;
	}
};

#endif // !REPEATUNTILFAIL_H

