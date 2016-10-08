/***************************************************************************
** Program Filename: input.hpp
** Author: Edwin Grove
** Date: 28/1/2016
** Description: The header file for the input class
** Input: string s
** Output: none
****************************************************************************/


#ifndef INPUTCHECK_HPP
#define INPUTCHECK_HPP
#include <string>
using std::string;

class input
{
private:
	string s;												//user input that will be used to return integer or double
	bool check;												//used to loop input checks
	int decCount;											//counts number of decimals in checkDouble() 
public:
	input();
	~input() {}
	int unsignedInt();
	int signedInt();
	double checkDouble();
	int negNum;
};

#endif // !INPUTCHECK_HPP

