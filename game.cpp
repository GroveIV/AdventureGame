/*********************************************************************************************************
** Program Filename: game.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: Game class definition and functions
** Input: None
** Output: None
**********************************************************************************************************/

#include "game.hpp"

/*********************************************************************************************************
** Constructor - takes a spaces pointer to a derived class and an inventory pointer 
**********************************************************************************************************/

game::game(spaces *R, inventory *backpack)
{
	this->backpack = backpack;
	currLoc = R;									//sets player's current location at start of game
	demonsPrompt1 = "\nAs you and Sig enter the circular room you jump as you hear movements, behind one of the closed doors\n"
		"accompanied by sinister sounding whispers that seem to travel farther than a whisper should.  You can't quite\n"
		"make out the words but there is a gleeful malace within the sounds that cannnot be mistaken.\n\n"
		"You: \"What was that?\"\n"
		"Sig: \"Those are your inner demons.  They thrive on idleness and use fear like a homing beacon to find their\n"
		"prey. In this case their prey is you. We should collect the items that you need quickly, there is nothing they\n"
		"despise more than a person comfortable in their own mind.";
	demonsPrompt2 = "\nAs you face the circular room you once again hear the dreaded sounds of the demons.  The strange\n"
		"whispers are more present in your ear and sound more sinister than before despite the fact that the specific\n"
		"words are no more lucid than before.";
	endDemons = "Sig: \"I think you have collected everything you need to make yourself comfortable here.\"\n"
		"You: \"I think you are right, I feel at home already\"\n\n"
		"Just as the last word rolls off your tongue you see the doors to all the other rooms open and out comes a flood\n"
		"of creatures, the likes of which you have never seen.  Each creature is uniquely horrendous, some are tall, gangly\n"
		"things with long faces and longer appendages who seem bent double as if they spent their lives crawling through\n"
		"spaces too small for their extended forms.  Other creatures are shorter with skeletal protrusions that seem to be\n"
		"attempting to poke through the thin grey skin that tightly covers their sickly looking, warped bodies.\n"
		"You can feel the panic start to rise in your chest as you pick up Sig and start scanning the room for a way to\n"
		"escape.  You can feel Sig shaking in your arms.\n"
		"A creature breaks out from the pack surrounding you and begins to walk towards you. It stops less than five feet\n"
		"away and starts speaking in a raspy voice that sounds as if it hadn't spoken for some time and had spent that time\n"
		"massaging its vocal cords with broken glass.\n\n"
		"Creature: \"You can't avoid us forever.\"\n"
		"You: \"Wha-wha-what do you want from us?\"\n"
		"Creature: \"That is an interesting question.  You seem to be attempting to make a home of this place, but you have\n"
		"neglected to consult us about this master plan.  We have been this place's tenants for almost as long as you have\n"
		"and I don't suspect that we will be going anywhere anytime soon. Much like you we did not choose to inhabit this\n"
		"place and much like you we are trying to make this place our home.  In many ways we are two sides of the same coin\n"
		"and the more we ignore each other the more we will haunt each other's existence.\"\n"
		"You: \"So what can we do about it?\"\n"
		"Creature: \"We are not the life sucking demons you think we are. We are just as much a part of you as your cat there.\n"
		"Give us a chance to get to know each other and I think we will find some common ground.\"\n\n"
		"You hesitantly nod, still fearing the creatures that surround you but, seeing no other way out, you have no choice but\n"
		"to acquiesce.\n\n"
		"The creatures let you pass through into your bedroom and you use the items you collected to make the room into a\n"
		"comfortable space. The creatures peer in from outside the door and as you watch them out of the corner of your eye\n"
		"you can see a timidness in their movements, as if they are curious children looking in on previously forbidden area.\n"
		"This is a trait that you had not expected to find and your initial impressions begin to change.  Maybe you misjudged\n"
		"these beings. Maybe with some time you can not only find a home for yourself but help these creatures find a home within\n"
		"these walls as well.  Besides, it is not like leaving is an option.\n\n"
		"THE END.";
	altEnd = "As Sig leads you to the room you hear the sound of a door opening behind you.  Before you can turn around something\n"
		"grabs you from behind and starts pulling you across the floor.  You panic and thrash about but it does you no good.\n"
		"A voice that sounds like gravel being dumped onto concrete starts speaking.\n\n"
		"Creature: \"You took too long and now you will be a victim to your your own mind.\n\n"
		"Your inner demons have taken you.\n\n"
		"You Lost\n";
	demons.push_back( demonsPrompt1 );
	demons.push_back( demonsPrompt2 );
	demNum = 0;
}

/*********************************************************************************************************
** Function: void currentLocation(spaces * R)
** Description: sets current location according to parameter passed into function
** Parameters: spaces * R (a spaces class pointer pointing to a derived class)
** Pre-conditions: parameters must be initialized before function call
** Post-conditions: class variable currLoc location is set to the parameter location
**********************************************************************************************************/

void game::currentLocation(spaces * R)
{
	currLoc = R;
}

/*********************************************************************************************************
** Function: void changeLocation()
** Description: calls currLoc changeRoom function in order to get user information about next location and
**				then sends that information to the currentLocation function
** Parameters: none
** Pre-conditions: currLoc must be set before this function is called with changeRoom() defined 
** Post-conditions: information returned from currLoc->changeRoom() is passed to the currentLocation() function
**********************************************************************************************************/

void game::changeLocation()
{
	currentLocation(currLoc->changeRoom());
}

/**********************************************************************************************************
** Function: void playGame()
** Description: Controls the flow of the game by switching between menus and locations. Ends when game is 
**				complete
** Parameters: none
** Pre-Conditions: All spaces derived classes must be initialized
** Post-Conditions: none
***********************************************************************************************************/

void game::playGame()
{
	int count = 0;
	bool loop = false;
	while (!loop && count < 10)
	{
		count++;
		currLoc->localMenu();
		loop = backpack->checkItems();
		if (!loop)
		{
			if (count == 3 || count == 6)				//output text about demons after changing rooms 3 times
			{
				std::cout << demons[demNum] << std::endl;
				demNum++;
			}
			changeLocation();
			loop = backpack->checkItems();
		}
	}
	if (count < 10)
	{
		std::cout << endDemons << std::endl;
	}
	else
	{
		std::cout << altEnd;
	}
}
