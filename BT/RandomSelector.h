#ifndef RANDOMSELECTOR_H
#define RANDOMSELECTOR_H

#include"CompositeNodeVec.h"

class RandomSelector : public CompositeNodeVec   // RandomSelector operates as a Selector, but in a random order instead of from first child to last child.
{
public:
	virtual bool run() override 
	{
		for (Node* child : childrenShuffled()) // The order is shuffled
		{
			if (child->run())
			{
				return true;
			}
		}
		return false;
	}
};

#endif // !RANDOMSELECTOR_H
