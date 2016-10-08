#include "menu.hpp"

spaces *menu::createDestMenu(std::string & prompt, std::vector<std::pair<spaces *, std::string> > &choice, inventory *backpack) 
{									//inspiration for menu functions from: 
	userCh = 0;							//codereview.stackexchange.com/questions/49614/text-based-adventure-game-with-too-many-conditional-statments
	bool loop1 = false;						//username: Edward (edited by: Morwenn
	while (!loop1)
	{
		userCh = 0;
		std::cout << prompt << std::endl;
		for (int i = 0; i < choice.size(); i++)
		{
			std::cout << i + 1 << ") " << choice[i].second << std::endl;
		}
		while (userCh < 1 || userCh > choice.size())
		{
			userCh = u.unsignedInt();
			if (userCh < 1 || userCh > choice.size())
				std::cout << "\nEnter a number corresponding to the menu choices" << std::endl;
		}
		if (userCh == choice.size())
		{
			backpack->spacesLeft();
		}
		else
		{
			loop1 = true;
		}
	}
	return choice[userCh - 1].first;
}

void menu::createLocMenu(std::string & prompt, std::vector<std::pair<std::string, 
	std::string> > choice, std::string & item, inventory *backpack, int *count, int itemNum, int exit)
{
	loop = false;
	while (!loop)											//looping menu until user receives item or wants
	{												//to change rooms
		userCh = 0;
		std::cout << prompt;
		for (int i = 0; i < choice.size(); i++)							//iterate through vector to output menu info
		{
			std::cout << i + 1 << ") " << choice[i].first << std::endl;			//outputting menu options for user
		}
		while (userCh < 1 || userCh > choice.size())						//get user choice. If input is erroneous loop until correct
		{
			userCh = u.unsignedInt();
		}
		std::cout << choice[userCh - 1].second << "\n" << std::endl;				//output result of user choice
		if (userCh == itemNum)									//itemNum defines the menu choice that leads to an item
		{
			if (*count > 0)
				std::cout << "You already have the " << item << "\n" << std::endl;
			else
			{
				(*count)++;
				backpack->addItem(item);
				std::cout << "[" << item << " has been added to your inventory]\n" << std::endl;
				std::cout << gotItem;
			}
		}
		if (userCh == exit)
		{
			loop = true;
		}
		if (userCh == choice.size())
			backpack->printItems();
	}
}
