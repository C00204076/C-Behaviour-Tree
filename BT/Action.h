#ifndef ACTION_H
#define ACTION_H

#include "Node.h"

class Action : public Node 
{
public:
	Action(const std::string newName, int prob) : 
		name(newName), 
		probabilityOfSuccess(prob) 
	{

	}

private:
	std::string name;
	int probabilityOfSuccess;

	virtual bool run() override 
	{
		if (std::rand() % 100 < probabilityOfSuccess) 
		{
			std::cout << name << " succeeded." << std::endl;
			return true;
		}
		std::cout << name << " failed." << std::endl;
		return false;
	}
};

#endif // !ACTION_H

