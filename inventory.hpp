/*********************************************************************************************************
** Program Filename: inventory.hpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: The header file for the inventory class
** Input: None
** Output: None
**********************************************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP


#include <string>
#include <iostream>
#include <vector>
#include <utility>


class inventory
{
public:
	inventory();
	~inventory() {}
	void addItem(std::string s);
	bool checkItems();
	bool checkForItem(std::string item);
	void printItems();
	void spacesLeft();
private:
	std::vector<std::pair<int, std::string> > items;
	std::string backpack;
	std::string feather;
	std::string pillow;
	std::string book;
	std::string guitar;
	std::string catFood;
	std::string bedroom;
	std::string movieRoom;
	std::string buildRoom;
	std::string subRoom;
	std::string abstractRoom;
	std::string senseRoom;
	std::vector<std::string> itemRooms;
};

#endif // !INVENTORY_HPP
