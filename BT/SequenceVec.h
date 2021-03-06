#ifndef SEQUENCEVEC_H
#define SEQUENCEVEC_H

#include "CompositeNodeVec.h"

class SequenceVec : public CompositeNodeVec {
public:
	virtual bool run() override 
	{
		for (Node* child : getChildren()) // The generic Sequence implementation.
		{
			if (!child->run())  // If one child fails, then enter operation run() fails.  Success only results if all children succeed.
			{
				return false;
			}
		}

		return true;  // All children suceeded, so the entire run() operation succeeds.
	}
};

#endif // !SEQUENCEVEC_H