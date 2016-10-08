/*********************************************************************************************************
** Program Filename: buildRoom.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: Defines the buildRoom class as well as all the functions and variables that make it up
** Input: None
** Output: None
**********************************************************************************************************/

#include "buildRoom.hpp"

/*********************************************************************************************************
** Constructor - takes an 'inventory' class pointer variable
**********************************************************************************************************/

buildRoom::buildRoom(inventory *backpack)
{
	description = "You are now in the build room";
	R2 = 0;
	R3 = 0;
	R5 = 0;
	R6 = 0;
	itemNum = 3;
	itemCount = 0;
	exit = 4;
	guitar = "guitar";
	prompt = "\nWhat would you like to build?\n";
	destPrompt = "Where would you like to go?";
	roomPrompt = "Sig leads you across the circular room and stops in front of a door that says, \"Build Room\". To the right\n"
		"of the door is a desk with a large binder seemingly filled with paper.\n\n"
		"Sig: \"Before you enter this room you must have some instructions about what you want to build while inside.\n"
		"The object you construct can be very helpful during your time here or it can be useless or even harmful. The\n"
		"building instructions are all in that binder to your right. Be careful what you choose to make, some of the\n"
		"instructions are convoluted and misleading or create an object you may not want. It is important to pay\n"
		"attention to the source of the instructions when choosing. Some of the instructions were written by your friends\n"
		"or family, others were laid out by cultural influences or a combination of both. There are even some written by\n"
		"you, although you probably never realized you were doing it. Choose wisely and you may receive a priceless item\"";
	option1 = "Construct a siege weapon (written by your friends)";
	answer1 = "You: \"A siege weapon! That sounds awesome!\"\n\n"
		"You rip out the instructions and head into the room.  From outside the door Sig can hear the sound of whirring\n"
		"machinery, the clanging of metal on metal and the frustrated mutterings of the builder working through less than\n"
		"ideal instructions.  Suddenly a yell of triumph permeates through the door quickly followed by a yelp of fear as\n"
		"the builder comes hurredly out, slamming the door behind him just as the door shakes as if hit from a large object\n\n"
		"You: \"The trebuchet worked wonderfully but it seems as it is was rigged to fire its ammunition directly at my head.\"\n"
		"Sig: \"Maybe you should try a different set of instructionsl\"";
	option2 = "Construct an exo-suit (written by cultural influence)";
	answer2 = "You: \"An exo-suit could come in handy, especially if those inner demons end up getting to me\"\n\n"
		"You head into the build room and start building the exo-suit.  The instructions are clearly written and provide many\n"
		"examples to work from.  The process is so well laid out that it seems hard to go wrong at any point in the process.\n"
		"You finish the construction of the exo-suit and step back to admire your handy work.\n\n"
		"Sig: \"Hmmm... Not really what the picture looked like\"\n"
		"You: \"No kidding.  It is not exactly the most ergonomic looking thing.  There are no joints for movement and the\n"
		"helmet doesn't have any eyeholes. I would feel pretty stifled in that thing.\"\n\n"
		"You and Sig head back out of the room to pick another set of instructions.";
	option3 = "Construct a guitar (written by you)";
	answer3 = "You grab the instructions for the guitar and head into the build room.  You follow the instructions but\n"
		"also throw in a few of your own ideas and spontaneous inspirations during construction.  You lose track of time\n"
		"and become wholly engrossed in the process.  When you put the finishing touch on the guitar a sense of pride and\n"
		"and tranquility is present on your face.\n"
		"Sig: \"Looks like you picked the right instruction.\"\n"
		"You sling the guitar across your back and leave the room.";
	option4 = "Go to a different Room";
	answer4 = "You turn your back on the build room to face the circular room.";
	destHint = "Hint";
	destHint1 = 0;
	locVec.push_back(std::make_pair(option1, answer1));
	locVec.push_back(std::make_pair(option2, answer2));
	locVec.push_back(std::make_pair(option3, answer3));
	locVec.push_back(std::make_pair(option4, answer4));
	locVec.push_back(std::make_pair(checkInv, ""));
	this->backpack = backpack;
}

/***********************************************************************************************************
** Function: void setPointers(spaces ** rooms)
** Description: Sets 'spaces' pointer variables to memory locations contained by a 'spaces' array of derived
**				classes
** Parameters: spaces ** rooms (an array holding pointers to derived 'spaces' classes)
** Pre-conditions: parameters must be initialized before calling this function
** Post-conditinos: 'spaces' pointer class variables become initialized
************************************************************************************************************/

void buildRoom::setPointers(spaces ** rooms)
{
	R2 = rooms[1];
	R3 = rooms[2];
	R5 = rooms[4];
	R6 = rooms[5];
	destVec.push_back(std::make_pair(R2, "The Movie Room"));
	destVec.push_back(std::make_pair(R3, "The Sensory Room"));
	destVec.push_back(std::make_pair(R5, "The Abstract Thought Room"));
	destVec.push_back(std::make_pair(R6, "The Subconcious Room"));
	destVec.push_back(std::make_pair(destHint1, destHint));
}

/************************************************************************************************************
** Function: spaces *changeRoom()
** Description: Opens a menu of choices for the user to choose from. Returns a pointer to a derived 'spaces' class
** Paramters: none
** Pre-Conditions: none
** Post-Conditions: returns a poiter to a derived 'spaces' class
*************************************************************************************************************/

spaces * buildRoom::changeRoom()
{
	return (dest.createDestMenu(destPrompt, destVec, backpack));
}

/************************************************************************************************************
** Function: void localMenu()
** Description: defines the options for this particular room that the user has to play through
** Parameters: none
** Pre-Conditions: class must be linked to the menu class
** Post-Conditions: Output user scenarios
*************************************************************************************************************/

void buildRoom::localMenu()
{
	if (itemCount == 0)
	{
		std::cout << roomPrompt << std::endl;
		dest.createLocMenu(prompt, locVec, guitar, backpack, &itemCount, itemNum, exit);
	}
	else															//if user already has item from room
	{
		std::cout << "You already have all the items you need from this room";
	}
}
