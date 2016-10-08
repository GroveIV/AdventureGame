/***************************************************************************************************
** Program Filename: main.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The driver function for a text based game
** Input: none
** Output: intro.txt
****************************************************************************************************/

#include "abstractRoom.hpp"
#include "buildRoom.hpp"
#include "game.hpp"
#include "movieRoom.hpp"
#include "senseRoom.hpp"
#include "spaces.hpp"
#include "subRoom.hpp"
#include "bedroom.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
	string line;
	std::ifstream intro("Intro.txt");
	inventory backpack;
	spaces **room = new spaces*[6];
	room[0] = new bedroom(&backpack);
	room[1] = new movieRoom(&backpack);
	room[2] = new senseRoom(&backpack);
	room[3] = new buildRoom(&backpack);
	room[4] = new abstractRoom(&backpack);
	room[5] = new subRoom(&backpack);
	room[0]->setPointers(room);
	room[1]->setPointers(room);
	room[2]->setPointers(room);
	room[3]->setPointers(room);
	room[4]->setPointers(room);
	room[5]->setPointers(room);

	

	if (intro.is_open())								//opening and outputting intro.txt file
	{
		while (std::getline(intro, line))
		{
			std::cout << line << '\n';
		}
		intro.close();
	}
	std::cout << std::endl;

	game player(room[0], &backpack);

	player.playGame();

	for (int i = 0; i < 6; i++)
	{
		delete room[i];
	}
	delete room;


	return 0;

}