#ifndef DOORBEHAVIOURDEC_H
#define DOORBEHAVIOURDEC_H

#include<string>
#include <stack>

#include "Node.h"

struct Door 
{
	int doorNumber;
};

class Building 
{
private:
	
public:
	Building(int numDoors) 
	{ 
		initializeBuilding(numDoors); 
	}

	const std::stack<Door*>& getDoors() const 
	{ 
		return doors; 
	}

private:
	std::stack<Door*> doors;

	void initializeBuilding(int numDoors) 
	{
		for (int i = 0; i < numDoors; i++)
		{
			doors.push(new Door{ numDoors - i });
		}
	}
};

struct DataContext   // Acts as a storage for arbitrary variables that are interpreted and altered by the nodes.
{
	std::stack<Door*> doors;
	Door* currentDoor;
	Door* usedDoor = nullptr;
};

class DoorAction : public Node 
{
public:
	DoorAction(const std::string newName, int prob) : 
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

#endif // !DOORBEHAVIOURDEC_H

