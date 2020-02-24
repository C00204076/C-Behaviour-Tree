#ifndef REPEATER_H
#define REPEATER_H

#include "DecoratorNode.h"

class Repeater : public DecoratorNode   // A repeater will reprocess its child node each time its child returns a result. These are often used at the very base of the tree, to make the tree to run continuously. Repeaters may optionally run their children a set number of times before returning to their parent.
{
private:
	int numRepeats;
	static const int NOT_FOUND = -1;

	Repeater(int num = NOT_FOUND) : numRepeats(num) // By default, never terminate.
	{

	}
	
	virtual bool run() override 
	{
		if (numRepeats == NOT_FOUND) 
		{
			while (true)
			{
				getChild()->run();
			}
		}

		else 
		{
			for (int i = 0; i < numRepeats - 1; i++)
			{
				getChild()->run();
			}

			return getChild()->run();
		}
	}
};

#endif // !REPEATER_H

