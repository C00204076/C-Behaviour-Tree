#ifndef SEQUENCEDEC_H
#define SEQUENCEDEC_H

#include "CompositeNodeDec.h"

class SequenceDec : public CompositeNodeDec 
{
public:
	virtual bool run() override 
	{
		for (Node* child : getChildren())   // The generic Sequence implementation.
		{
			if (!child->run())  // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
			{
				return false;
			}
		}
		return true;  // All children suceeded, so the entire run() operation succeeds.
	}
};

#endif // !SEQUENCEDEC_H

