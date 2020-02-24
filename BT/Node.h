#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <initializer_list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>

class Node // This class represents each node in the behaviour tree.
{
public:
	virtual bool run() = 0;
};

#endif // !NODE_H