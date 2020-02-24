#ifndef STACKNODE_H
#define STACKNODE_H

#include "Node.h"

template <typename T>
class StackNode : public Node 
{
protected:
	std::stack<T*>& stack;  // Must be reference to a stack to work.
	StackNode(std::stack<T*>& s) : stack(s) 
	{

	}
};

template <typename T>
class PushToStack : public StackNode<T>   // Specific type of leaf (hence has no child).
{
public:
	PushToStack(T*& t, std::stack<T*>& s) : StackNode<T>(s), item(t) 
	{

	}

private:
	T*& item;

	virtual bool run() override 
	{
		this->stack.push(item);
		return true;
	}
};

template <typename T>
class GetStack : public StackNode<T>   // Specific type of leaf (hence has no child).
{
public:
	GetStack(std::stack<T*>& s, const std::stack<T*>& o, T* t = nullptr) : 
		StackNode<T>(s), 
		obtainedStack(o), 
		object(t) 
	{

	}

private:
	const std::stack<T*>& obtainedStack;
	T* object;

	virtual bool run() override 
	{
		this->stack = obtainedStack;
		if (object)
		{
			this->stack.push(object);
		}
		return true;
	}
};

template <typename T>
class PopFromStack : public StackNode<T>  // Specific type of leaf (hence has no child).
{
public:
	PopFromStack(T*& t, std::stack<T*>& s) : StackNode<T>(s), item(t) 
	{

	}

private:
	T*& item;

	virtual bool run() override 
	{
		if (this->stack.empty())
		{
			return false;
		}

		item = this->stack.top();
		std::cout << "Trying to get through door #" << item->doorNumber << "." << std::endl;  // template specialization with T = Door needed for this line actually
		this->stack.pop();
		return true;
	}
};

template <typename T>
class StackIsEmpty : public StackNode<T>   // Specific type of leaf (hence has no child).
{
public:
	StackIsEmpty(std::stack<T*>& s) : StackNode<T>(s) 
	{

	}

private:
	virtual bool run() override 
	{
		return this->stack.empty();
	}
};

#endif // !STACKNODE_H

