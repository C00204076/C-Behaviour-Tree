#ifndef DECORATORNODE_H
#define DECORATORNODE_H

#include "Node.h"

class DecoratorNode : public Node {  // Function is either to transform the result it receives from its child node's status, to terminate the child, or repeat processing of the child, depending on the type of decorator node.
private:
	Node* child;  // Only one child allowed

protected:
	Node* getChild() const { return child; }

public:
	void setChild(Node* newChild) { child = newChild; }
};

#endif // !DECORATORNODE_H

