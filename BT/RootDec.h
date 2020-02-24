#ifndef ROOTDEC_H
#define ROOTDEC_H

#include "DecoratorNode.h"

class RootDec : public DecoratorNode 
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

#endif // !ROOTDEC_H

