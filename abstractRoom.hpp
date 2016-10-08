/*********************************************************************************************************
** Program Filename: abstractRoom.hpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The header file for the abstractRoom derived class (parent class = spaces)
** Input: None
** Output: None
**********************************************************************************************************/

#ifndef ABSTRACTROOM_HPP
#define ABSTRACTROOM_HPP

#include "spaces.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <vector>


class abstractRoom : public spaces								//room 5
{
public:
	abstractRoom() {}
	abstractRoom(inventory *backpack);
	~abstractRoom() {}
	void setPointers(spaces **rooms);
	spaces *changeRoom();
	void localMenu();
private:
	std::string description;
	int choice;
	int itemCount;
	int itemNum;
	int exit;
	menu dest;
	std::vector <std::string> test1;
	std::string prompt;
	std::string destPrompt;
	std::string roomPrompt1;
	std::string roomPrompt2; 
	std::string option11;
	std::string answer11;
	std::string option21;
	std::string answer21;
	std::string option31;
	std::string answer31;
	std::string option41;
	std::string answer41;
	std::string menuPrompt;
	std::string option12;
	std::string answer12;
	std::string option22;
	std::string answer22;
	std::string option32;
	std::string answer32;
	std::string option42;
	std::string answer42;
	std::string destHint;
	spaces *destHint1;
	spaces *R2;
	spaces *R3;
	spaces *R4;
	spaces *R6;
	inventory *backpack;
	std::string book;
	std::vector<std::pair<std::string, std::string> > locVec;
	std::vector<std::pair<spaces *, std::string> > destVec;
};

#endif // !ABSTRACTROOM_HPP

