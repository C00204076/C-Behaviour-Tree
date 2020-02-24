#ifndef DOORBEHAVIOUR_H
#define DOORBEHAVIOUR_H

#include "Node.h"

struct DoorStatus {
	bool doorIsOpen;
	int distanceToDoor;
};

class CheckIfDoorIsOpenTask : public Node // Each task will be a class (derived from Node of course).
{
private:
	DoorStatus* status;

public:
	CheckIfDoorIsOpenTask(DoorStatus* status) : status(status) 
	{
	
	}
	
	virtual bool run() override
	{
		if (status->doorIsOpen == true)
		{
			std::cout << "The person sees that the door is open." << std::endl;  // will return true
		}
		else
		{
			std::cout << "The person sees that the door is closed." << std::endl;  // will return false
		}
		return status->doorIsOpen;
	}

};

class ApproachDoorTask : public Node 
{
private:
	DoorStatus* status;
	bool obstructed;

public:
	ApproachDoorTask(DoorStatus* status, bool obstructed) : status(status), obstructed(obstructed) 
	{

	}
	
	virtual bool run() override
	{
		if (obstructed)
			return false;
		if (status->distanceToDoor > 0) 
		{
			std::cout << "The person approaches the door." << std::endl;
			status->distanceToDoor--;  // thus run() is not a const function
			
			if (status->distanceToDoor > 1)
			{
				std::cout << "The person is now " << status->distanceToDoor << " meters from the door." << std::endl;
			}

			else if (status->distanceToDoor == 1)
			{
				std::cout << "The person is now only one meter away from the door." << std::endl;
			}

			else
			{
				std::cout << "The person is at the door." << std::endl;
			}
		}

		return true;
	}
};

class OpenDoorTask : public Node 
{
private:
	DoorStatus* status;

public:
	OpenDoorTask(DoorStatus* status) : status(status) 
	{
	
	}

	virtual bool run() override
	{
		if (status->distanceToDoor > 0) 
		{
			std::cout << "The person is still too far away from the door.  He cannot open the door." << std::endl;
			return false;
		}

		status->doorIsOpen = true;  // run() not const because of this too
		std::cout << "The person opens the door." << std::endl;
		return true;
	}
};
#endif // !DOORBEHAVIOUR_H