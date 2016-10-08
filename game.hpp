/*********************************************************************************************************
** Program Filename: game.hpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The header file for the game class
** Input: None
** Output: None
**********************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "inventory.hpp"
#include "spaces.hpp"
#include <iostream>	
#include <string>
#include <vector>


class game
{
public:
	game() {}
	game(spaces *R, inventory *backpack);
	~game() {}
	void currentLocation(spaces *R);
	void changeLocation();
	void playGame();
private:
	spaces *currLoc;
	inventory *backpack;
	std::string demonsPrompt1;
	std::string demonsPrompt2;
	std::string endDemons;
	std::string altEnd;
	std::vector<std::string> demons;
	int demNum;
};

#endif // !GAME_HPP

