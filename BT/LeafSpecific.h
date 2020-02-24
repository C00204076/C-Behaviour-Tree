#ifndef LEAFSPECIFIC_H
#define LEAFSPECIFIC_H

#include "Node.h"

template <typename T>
class SetVariable : public Node   // Specific type of leaf (hence has no child).
{
public:
	SetVariable(T*& t, T*& obj) : variable(t), object(obj) 
	{
	
	}

	virtual bool run() override 
	{
		variable = object;
		std::cout << "The door that was used to get in is door #" << variable->doorNumber << "." << std::endl;  // template specialization with T = Door needed for this line actually
		return true;
	};

private:
	T*& variable, *& object;  // Must use reference to pointer to work correctly.
};

template <typename T>
class IsNull : public Node   // Specific type of leaf (hence has no child).
{

public:
	IsNull(T*& t) : object(t) 
	{

	}

	virtual bool run() override 
	{ 
		return !object; 
	}

private:
	T*& object;  // Must use reference to pointer to work correctly.
};

#endif // !LEAFSPECIFIC_H

