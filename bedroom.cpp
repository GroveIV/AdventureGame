/*********************************************************************************************************
** Program Filename: bedroom.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: Defines the bedroom class as well as all the functions and variables that make it up
** Input: None
** Output: None
**********************************************************************************************************/

#include "bedroom.hpp"

/*********************************************************************************************************
** Constructor - takes an 'inventory' class pointer variable
**********************************************************************************************************/

bedroom::bedroom(inventory *pack)
{
	prompt = "You are standing in the middle of your room, your cat is still lying on the bed looking at you expectantly and there"
		" is a backpack on the floor.\n";
	roomPrompt = "What do you want to do?\n";
	destPrompt = "Where would you like to go?";
	option1 = "Look around the room";
	answer1 = "\nYou look around the familiar but alien decor of your room.  There is a bed but no linens or pillows.  There is a \n"
		"bookshelf but no books.  All the items that make your room comforting and inviting are gone making it seem barren.\n"
		"There is a backpack sitting on the floor though\n";
	option2 = "Pet your cat Sig";
	answer2 = "\nYou reach down and pet Sig along the back\nSig: \"You do realize that you are literally stroking your own ego right now\".\n";
	option3 = "Pick up backpack";
	answer3 = "\nYou reach down and pick up your backpack, Sig gives a nod of approval";
	option4 = "Go to a different room";
	answer4 = "\nYou: \"Alright Sig, I am ready to leave.  Show me the way through my mind.\"\n\n"
		"Sig stands and stretches before smoothly hopping off the bed.  You open the door and enter a circular room with doors\n"
		"spread out intermittently along the edge.";
	backpack = "backpack";
	destHint = "Hint";
	destHint1 = 0;
	itemCount = 0;
	itemNum1 = 3;
	itemNum2 = 0;
	exit1 = 3;
	exit2 = 2;
	locVec.push_back(std::make_pair(option1, answer1));
	locVec.push_back(std::make_pair(option2, answer2));
	locVec.push_back(std::make_pair(option3, answer3));
	locVec1.push_back(std::make_pair(option2, answer2));
	locVec1.push_back(std::make_pair(option4, answer4));
	locVec1.push_back(std::make_pair(checkInv, ""));

	this->bag = pack;
	
}

/***********************************************************************************************************
** Function: void setPointers(spaces ** rooms)
** Description: Sets 'spaces' pointer variables to memory locations contained by a 'spaces' array of derived
**				classes
** Parameters: spaces ** rooms (an array holding pointers to derived 'spaces' classes)
** Pre-conditions: parameters must be initialized before calling this function
** Post-conditinos: 'spaces' pointer class variables become initialized
************************************************************************************************************/

void bedroom::setPointers(spaces ** rooms)
{
	R2 = rooms[1];
	R3 = rooms[2];
	R4 = rooms[3];
	R5 = rooms[4];
	R6 = rooms[5];
	destVec.push_back(std::make_pair(R2, "The Movie Room"));
	destVec.push_back(std::make_pair(R3, "The Sensory Room"));
	destVec.push_back(std::make_pair(R4, "The Construction Room"));
	destVec.push_back(std::make_pair(R5, "The Abstract Reasoning Room"));
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

spaces * bedroom::changeRoom()
{
	return (dest.createDestMenu(destPrompt, destVec, bag));
}

/************************************************************************************************************
** Function: void localMenu()
** Description: defines the options for this particular room that the user has to play through
** Parameters: none
** Pre-Conditions: class must be linked to the menu class
** Post-Conditions: Output user scenarios
*************************************************************************************************************/

void bedroom::localMenu()
{
	std::cout << prompt << std::endl;
	dest.createLocMenu(roomPrompt, locVec,
		backpack, bag, &itemCount, itemNum1, exit1);
	dest.createLocMenu(roomPrompt, locVec1,
		backpack, bag, &itemCount, itemNum2, exit2);
}
