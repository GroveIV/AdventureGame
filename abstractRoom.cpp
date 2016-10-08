/*********************************************************************************************************
** Program Filename: abstractRoom.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: Defines the abstractRoom class and all of its functions.
** Input: None
** Output: None
**********************************************************************************************************/

#include "abstractRoom.hpp"

/*********************************************************************************************************
** Constructor - takes an 'inventory' class pointer 
**********************************************************************************************************/

abstractRoom::abstractRoom(inventory *backpack)
{
	choice = 0;
	itemCount = 0;
	itemNum = 4;
	exit = 4;
	destPrompt = "Where would you like to go?";
	R2 = 0;
	R3 = 0;
	R4 = 0;
	R6 = 0;
	this->backpack = backpack;
	prompt = "\nYou enter a room that is bewildering to behold.  Light shifts about the room so that areas oscillate\n"
		"lazily between dark and well-lit; strangely the source of these illuminations is not readily apparent.  You\n"
		"see semi-translucent shapes of different colors grow and diminish.  You hear half realized melodies loop\n"
		"and intertwine with one another yet somehow it sounds soothing instead of cacophonous.\n\n"
		"Sig: \"This is the abstract thinking room. It is the place where your imagination is free to explore the\n"
		"wildest ideas and thoughts that you can come up with. It is also the place where pattern recognition and\n"
		"intelligence come into play. I will be administering a couple tests you need to take in order to become \n"
		"comfortable with this area.  If you do well on the test you will receive an item that will help you\n"
		"immensely while here in your mind.\"\n";
	roomPrompt1 = "\nTest 1:\n";
	option11 = "Picture a blue ball";
	answer11 = "Good";
	option21 = "Now picture a red ball";
	answer21 = "Well done";
	option31 = "Now picture a yellow cube";
	answer31 = "So far so good";
	option41 = "Now picture a multicolored icosidodecahedron";
	answer41 = "Well you were good up to that last one, but not everyone \nis an Einstein";
	roomPrompt2 = "\nTest 2:\n";
	menuPrompt = "Fill in the blank:\nDuck, duck, goose. duck, duck, goose. duck, duck, ______.\n";
	option12 = "orangutan";
	answer12 = "Sig: \"You enjoyed the smell of rubber cement as a kid didn't you.\"\n";
	option22 = "duck";
	answer22 = "Sig: \"Given the words in the prompt and absolutely no critical thinking skills I am going to give you credit\"\n"
		"for recognizing you had about a 50/50 option here.  You are still not a smart person though.\n";
	option32 = "orange";
	answer32 = "Sig: \"Congratulations orange IS a homonym... I'm going to pretend that is what you were inferring.\"\n";
	option42 = "goose";
	answer42 = "Sig: \"Congratulations! You have now passed the abstraction tests.  You have the, somewhat limited, ability.\n"
		"to think abstractly and therefore you have all the necessary equipment to enjoy this book.\"\n"
		"You head back out the door and enter the circular room";
	destHint = "Hint";
	destHint1 = 0;
	test1.push_back(option11);
	test1.push_back(answer11);
	test1.push_back(option21);
	test1.push_back(answer21);
	test1.push_back(option31);
	test1.push_back(answer31);
	test1.push_back(option41);
	test1.push_back(answer41);
	locVec.push_back(std::make_pair(option12, answer12));
	locVec.push_back(std::make_pair(option22, answer22));
	locVec.push_back(std::make_pair(option32, answer32));
	locVec.push_back(std::make_pair(option42, answer42));
	book = "book";
}

/***********************************************************************************************************
** Function: void setPointers(spaces ** rooms)
** Description: Sets 'spaces' pointer variables to memory locations contained by a 'spaces' array of derived 
**				classes
** Parameters: spaces ** rooms (an array holding pointers to derived 'spaces' classes)
** Pre-conditions: parameters must be initialized before calling this function
** Post-conditinos: 'spaces' pointer class variables become initialized
************************************************************************************************************/

void abstractRoom::setPointers(spaces ** rooms)
{
	R2 = rooms[1];
	R3 = rooms[2];
	R4 = rooms[3];
	R6 = rooms[5];
	destVec.push_back(std::make_pair(R2, "The Movie Room"));
	destVec.push_back(std::make_pair(R3, "The Sensory Room"));
	destVec.push_back(std::make_pair(R4, "The Construction Room"));
	destVec.push_back(std::make_pair(R6, "The Subconcious Room"));
	destVec.push_back(std::make_pair(destHint1, destHint));
}

/************************************************************************************************************
** Function: spaces *changeRoom()
** Description: Opens a menu of choices for the user to choose from. Returns a pointer to a derived 'spaces' class
** Paramters: none
** Pre-Conditions: class must be linked to the menu class
** Post-Conditions: returns a poiter to a derived 'spaces' class
*************************************************************************************************************/

spaces * abstractRoom::changeRoom()
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

void abstractRoom::localMenu()
{
	if (itemCount == 0)
	{
		std::cout << prompt << std::endl;						//Introduction to room
		std::cout << roomPrompt1;
		spaces::pressToContinue();
		for (int i = 0; i < test1.size(); i += 2)				//output different prompts for the user to read
		{
			spaces::sleep(700);									//causes the output to pause for 700 milliseconds
			std::cout << test1[i];
			for (int j = 0; j < 3; j++)
			{
				spaces::sleep(2000);							//output pauses for 2 seconds
				std::cout << ". ";
			}
			std::cout << test1[i + 1] << std::endl;
		}
		std::cout << roomPrompt2 << std::endl;
		dest.createLocMenu(menuPrompt, locVec, book, backpack, &itemCount, itemNum, exit);
	}
	else														//If user has already received item from room
	{
		std::cout << "You already have the item you need from this room" << std::endl;
	}

}


