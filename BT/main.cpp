
#include "Selector.h"
#include "Sequence.h"

#include "RandomSelector.h"
#include "SelectorVec.h"
#include "SequenceVec.h"
#include "Root.h"
#include "Action.h"

#include "CompositeNodeDec.h"
#include "SelectorDec.h"
#include "RandomSelectorDec.h"
#include "SequenceDec.h"
#include "RootDec.h"
#include "Inverter.h"
#include "Succeeder.h"
#include "Failer.h"
#include "Repeater.h"
#include "RepeatUntilFail.h"
#include "StackNode.h"
#include "LeafSpecific.h"
#include "DoorBehaviourDec.h"

#include "DoorBehaviour.h"

// C++ Behaviour Tree based-off: http://www.cplusplus.com/forum/general/141582/
// Brandon Seah-Dempsey
// C00204076
// Started at 10:00 24 Feburary 2020
// Finished at 13:34 24 Feburary 2020
// Time taken: 3 hours
// Known bugs: Third behaviour ignores return 0;


/*

		Root
			 |
			 |
  Selector (only one of these children need to succeed)
	   /             \
	  /               \
	 /                 \
Door is open?      Sequence (all of these children need to succeed)
(if door is                /           \
already open,             /             \
we are done)             /               \
				   Approach door      Open the door
				  (if this fails
				  then the door
				  cannot be opened)
*/

int main()
{
	//Uncomment behaviours to test

	// Behaviour #1
	//Open a door behaviour - Small Behaviour tree(std::list)
	/*Sequence* root = new Sequence, * sequence1 = new Sequence;  // Note that root can be either a Sequence or a Selector, since it has only one child.

	Selector* selector1 = new Selector;  // In general there will be several nodes that are Sequence or Selector, so they should be suffixed by an integer to distinguish between them.
	
	DoorStatus* doorStatus = new DoorStatus{ false, 5 };  // The door is initially closed and 5 meters away.
	CheckIfDoorIsOpenTask* checkOpen = new CheckIfDoorIsOpenTask(doorStatus);
	ApproachDoorTask* approach = new ApproachDoorTask(doorStatus, false);
	OpenDoorTask* open = new OpenDoorTask(doorStatus);

	root->addChild(selector1);

	selector1->addChild(checkOpen);
	selector1->addChild(sequence1);

	sequence1->addChild(approach);
	sequence1->addChild(open);

	while (!root->run())  // If the operation starting from the root fails, keep trying until it succeeds.
	{
		std::cout << "--------------------" << std::endl;
	}

	std::cout << std::endl << "Operation complete.  Behaviour tree exited." << std::endl;
	std::cin.get();//*/
	//

	//Behaviour #2
	// Escape Room - Larger Behaviour tree(std::vector)
	/*Root root;
	std::srand(std::time(nullptr));
	SelectorVec selector[3];
	SequenceVec sequence[4];
	Action walkToDoor("Walk to door", 99), openDoor1("Open door", 15), unlockDoor("Unlock door", 25), openDoor2("Open door after unlocking it", 99), smashDoor("Smash door", 60),
		walkThroughDoor("Walk through door", 60), closeDoor("Close door", 100), walkToWindow("Walk to Window", 99), openWindow1("Open window", 70), unlockWindow("Unlock window", 65),
		openWindow2("Open window after unlocking it", 85), smashWindow("Smash window", 95), climbThroughWindow("Climb through window", 85), closeWindow("Close window", 100);

	root.setChild(&selector[0]);
	selector[0].addChildren({ &sequence[0],&sequence[2] });
	sequence[0].addChildren({ &walkToDoor, &selector[1], &walkThroughDoor, &closeDoor });
	selector[1].addChildren({ &openDoor1, &sequence[1], &smashDoor });
	sequence[1].addChildren({ &unlockDoor, &openDoor2 });
	sequence[2].addChildren({ &walkToWindow, &selector[2], &climbThroughWindow, &closeWindow });
	const std::list<Node*> nodes = { &openWindow1, &sequence[3], &smashWindow };
	selector[2].addChildren(nodes);
	sequence[3].addChildren({ &unlockWindow, &openWindow2 });

	if (root.run())
	{
		std::cout << "Congratulations!  You made it out!" << std::endl;
	}

	else
	{
		std::cout << "Sorry.  You are trapped here for life." << std::endl;
	}//*/
	//

	//Behaviour #3
	//Escape Building - Behaviour tree and Decorator Nodes
	/*std::srand(std::time(nullptr));

	RootDec rootDec;
	DataContext data;
	Building building(5);  // Building with 5 doors to get in.
	SequenceDec sequence[3];
	SelectorDec selector;
	Inverter inverter[2];
	Succeeder succeeder;
	RepeatUntilFail untilFail;
	GetStack<Door> getDoorStackFromBuilding(data.doors, building.getDoors());
	PopFromStack<Door> popFromStack(data.currentDoor, data.doors);
	SetVariable<Door> setVariable(data.usedDoor, data.currentDoor);
	IsNull<Door> isNull(data.usedDoor);
	DoorAction walkToDoor("Walk to door", 99), openDoor("Open door", 15), unlockDoor("Unlock door", 25), smashDoor("Smash door", 60), walkThroughDoor("Walk through door", 60), closeDoor("Close door", 100);

	rootDec.setChild(&sequence[0]);
	sequence[0].addChildren({ &getDoorStackFromBuilding, &untilFail, &inverter[0] });
	untilFail.setChild(&sequence[1]);
	inverter[0].setChild(&isNull);
	sequence[1].addChildren({ &popFromStack, &inverter[1] });
	inverter[1].setChild(&sequence[2]);
	sequence[2].addChildren({ &walkToDoor, &selector, &walkThroughDoor, &succeeder, &setVariable });
	selector.addChildren({ &openDoor, &unlockDoor, &smashDoor });
	succeeder.setChild(&closeDoor);

	if (rootDec.run())
	{
		std::cout << "Congratulations!  You made it into the building!" << std::endl;
	}

	else
	{
		std::cout << "Sorry.  You have failed to enter the building." << std::endl;
	}//*/
	//

	return 0;
}