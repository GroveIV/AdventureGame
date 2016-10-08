/*********************************************************************************************************
** Program Filename: buildRoom.hpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The header file for the buildRoom derived class (parent class = spaces)
** Input: None
** Output: None
**********************************************************************************************************/

#ifndef BUILDROOM_HPP
#define BUILDROOM_HPP

#include "spaces.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>


class buildRoom : public spaces							//room 4
{
public:
	buildRoom() {}
	buildRoom(inventory *backpack);
	~buildRoom() {}
	void setPointers(spaces **rooms);
	std::string getDescription()
	{
		return description;
	}
	spaces *changeRoom();
	void localMenu();
private:
	std::string description;
	std::string prompt;
	std::string roomPrompt;
	std::string option1;
	std::string answer1;
	std::string option2;
	std::string answer2;
	std::string option3;
	std::string answer3;
	std::string option4;
	std::string answer4;
	std::string destHint;
	spaces *destHint1;
	menu dest;
	int choice;
	int itemNum;
	int itemCount;
	int exit;
	spaces *R2;
	spaces *R3;
	spaces *R5;
	spaces *R6;
	inventory *backpack;
	std::string guitar;
	std::string destPrompt;
	std::vector<std::pair<std::string, std::string> > locVec;
	std::vector<std::pair<spaces *, std::string> > destVec;
};

#endif // !BUILDROOM_HPP

