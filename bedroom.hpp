/*********************************************************************************************************
** Program Filename: bedroom.hpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The header file for the abstractRoom derived class (parent class = spaces)
** Input: None
** Output: None
**********************************************************************************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "spaces.hpp"
#include "inventory.hpp"
#include "menu.hpp"
#include "input.hpp"
#include <iostream>
#include <string>


class bedroom :public spaces
{
public:
	bedroom() {}
	bedroom(inventory *pack);
	~bedroom() {}
	void setPointers(spaces **rooms);
	spaces *changeRoom();
	void localMenu();
private:
	std::string prompt;
	std::string roomPrompt;
	std::string destPrompt;
	std::string option1;
	std::string answer1;
	std::string option2;
	std::string answer2;
	std::string option3;
	std::string answer3;
	std::string option4;
	std::string answer4;
	std::string backpack;
	std::string destHint;
	menu dest;
	input u;
	int choice;
	int itemCount;
	int itemNum1;
	int itemNum2;
	int exit1;
	int exit2;
	spaces *destHint1;
	spaces *R2;
	spaces *R3;
	spaces *R4;
	spaces *R5;
	spaces *R6;
	inventory *bag;
	std::vector<std::pair<std::string, std::string> > locVec;
	std::vector<std::pair<std::string, std::string> > locVec1;
	std::vector<std::pair<spaces *, std::string> > destVec;
};

#endif // !BEDROOM_HPP

