#ifndef COMPOSITENODEDEC_H
#define COMPOSITENODEDEC_H

#include "Node.h"

class CompositeNodeDec : public Node   //  This type of Node follows the Composite Pattern, containing a list of other Nodes.
{

public:
	const std::vector<Node*>& getChildren() const 
	{ 
		return children; 
	}

	void addChild(Node* child) 
	{ 
		children.emplace_back(child); 
	}

	void addChildren(std::initializer_list<Node*>&& newChildren) 
	{ 
		for (Node* child : newChildren)
		{
			addChild(child);
		}
	}

	template <typename CONTAINER>
	void addChildren(const CONTAINER& newChildren) 
	{ 
		for (Node* child : newChildren) 
		{ 
			addChild(child); 
		}
	}

protected:
	std::vector<Node*> childrenShuffled() const { std::vector<Node*> temp = children;  std::random_shuffle(temp.begin(), temp.end());  return temp; }

private:
	std::vector<Node*> children;
};

#endif // !COMPOSITENODEDEC_H

