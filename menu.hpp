#ifndef MENU_HPP
#define MENU_HPP

#include "inventory.hpp"
#include "spaces.hpp"
#include "input.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class menu
{
public:
	menu() 
	{
		checkItem = 0;
		gotItem = "You now have all the items from this room.\n";
	}
	~menu() {}
  	spaces *createDestMenu(std::string &prompt, std::vector<std::pair< spaces *, std::string> > &choice, inventory *backpack);
	void createLocMenu(std::string &prompt, std::vector<std::pair<std::string, std::string> > ,
		std::string &item, inventory *backpack, int *count, int itemNum, int exit);

private:
	input u;
	int userCh;
	bool loop;
	int checkItem;
	std::string gotItem;
};

#endif // !DESTMENU_HPP
