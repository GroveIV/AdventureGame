/*********************************************************************************************************
** Program Filename: inventory.cpp
** Author: Edwin Grove
** Date: 3/11/2016
** Description: Functions and definitions for the inventory class.  Used to count user items throught he game
** Input: None
** Output: None
**********************************************************************************************************/

#include "inventory.hpp"

/*********************************************************************************************************
** Default Constructor - defines class variables
**********************************************************************************************************/

inventory::inventory()
{
	backpack = "backpack";
	feather = "feather";
	pillow = "pillow";
	book = "book";
	guitar = "guitar";
	catFood = "cat food";
	bedroom = "bedroom";
	senseRoom = "sensory room";
	movieRoom = "movie room";
	abstractRoom = "abstract reasoning room";
	buildRoom = "construction room";
	subRoom = "subconcious room";
	itemRooms.push_back(bedroom);
	itemRooms.push_back(senseRoom);
	itemRooms.push_back(movieRoom);
	itemRooms.push_back(abstractRoom);
	itemRooms.push_back(buildRoom); 
	itemRooms.push_back(subRoom);
	items.push_back(std::make_pair(0, backpack));
	items.push_back(std::make_pair(0, feather)); 
	items.push_back(std::make_pair(0, pillow)); 
	items.push_back(std::make_pair(0, book));
	items.push_back(std::make_pair(0, guitar));
	items.push_back(std::make_pair(0, catFood));
}

/*********************************************************************************************************
** Function: void addItem(std::string s)
** Description: finds the item in 'items' vector passed in by the parameter and makes the associated integer
**				value one
** Parameters: std::string s (a string matching one of the items in the items vector
** Pre-conditions: the parameters must have a value matching one of the values in the items vector
** Post-conditions: If 's' is found in items vector the associated integer is set to one
**********************************************************************************************************/

void inventory::addItem(std::string s)
{
	int i = 0;
	for (i; i < items.size(); i++)
	{
		if (items[i].second == s)
		{
			break;
		}
	}
	items[i].first = 1;
}

/**********************************************************************************************************
** Function: bool checkItem()
** Description: increments through items vector and checks if the integer value at each location is equal
				to zero.  If it is is means the item hasn't been found yet and return a false.  If no items
				integers are equal to 0 then all items have been found and it return true.
** Parameters: none
** Pre-Conditions: all call variable must be defined
** Post-Conditions: returns a true or false according to search results
***********************************************************************************************************/

bool inventory::checkItems()
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].first == 0)
			return false;
	}
	return true;
}

/***********************************************************************************************************
** Function: bool checkForItem(std::string item)
** Description: Searches for a specific string in items vector and checks if the associated integer is a one
				or a zero.  If it is a 1 then the function returns a true value. if not it returns false
** Parameters: std::string item
** Pre-conditions: parameters string value must be a value within the items vector
** Post-conditions: return true if items vector integer is 1, false if not
************************************************************************************************************/

bool inventory::checkForItem(std::string item)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].second == item && items[i].first == 1)				
			return true;
	}
	return false;
}

/***********************************************************************************************************
** Function: void printItems()
** Description: prints the pair of values (integer and string) associated with each vector spaces
** Parameters: none
** Pre-conditions: none
** Post-conditions: prints out values associated with each vector location
************************************************************************************************************/

void inventory::printItems()
{
	std::cout << "Inventory:" << std::endl;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].first == 1)
			std::cout << items[i].second << std::endl;
	}
	std::cout << '\n';
}

void inventory::spacesLeft()
{
	std::cout << "\nPlaces left to go:" << std::endl;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].first == 0)
			std::cout << itemRooms[i] << std::endl;
	}
	std::cout << std::endl;
}




