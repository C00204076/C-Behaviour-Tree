#ifndef RANDOMSELECTORDEC_H
#define RANDOMSELECTORDEC_H

#include "CompositeNodeDec.h"

class RandomSelectorDec : public CompositeNodeDec   // RandomSelector operates as a Selector, but in a random order instead of from first child to last child (adds more unpredictability to the behaviour when a there is no clear preferred order of execution).
{
public:
	virtual bool run() override
	{
		for (Node* child : childrenShuffled())   // The order is shuffled
		{
			if (child->run())
			{
				return true;
			}
		}
		return false;
	}
};

#endif // !RANDOMSELECTORDEC_H

