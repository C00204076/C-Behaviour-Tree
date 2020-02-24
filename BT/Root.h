#ifndef ROOT_H
#define ROOT_H

#include "Node.h"

class Root : public Node 
{
public:
	void setChild(Node* newChild)
	{
		child = newChild;
	}

	virtual bool run() override
	{
		return child->run();
	}

private:
	Node* child;
};

#endif // ROOT_H

