#ifndef COMPOSITENODE_H
#define COMPOSITENODE_H

#include "Node.h"

class CompositeNode : public Node //  This type of Node follows the Composite Pattern, containing a list of other Nodes.
{
public:
	void addChild(Node* child)
	{
		m_children.emplace_back(child);
	}

	const std::list<Node*>& getChildren() const
	{
		return m_children;
	}

private:
	std::list<Node*> m_children;
};
#endif // !COMPOSITENODE_H