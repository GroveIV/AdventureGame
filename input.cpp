/***************************************************************************************
** Program Filename: input.cpp
** Author: Edwin Grove
** Date: 28/1/2016
** Description: Checks user input of integers and doubles for validity
** Input: string s 
** Output: returns integer or double depending on function
****************************************************************************************/





#include "input.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// default constructor- initializes a couple of private variables
input::input()
{
	decCount = 0;
	check = false;
	negNum = 0;
}

/****************************************************************************************
** Function: unsignedInt()
** Description: Checks to make sure that user inputs a positive integer
** Parameters: none
** Pre-conditions: none
** Post-conditions: returns an integer value
*****************************************************************************************/


int input::unsignedInt()
{
	check = false;																//loops until user enters a correct value
	while (check != true)
	{
		cin >> s;																//user input as string
		for (int i = 0; i < s.size(); i++)										//loops through user input to check each character 
		{
			if (s.at(i) > 48 && s.at(i) < 58)									//checking if input is an integer by ascii value
			{
				check = true;
			}
			else
			{
				cout << "Please enter a number according to the menu choices" << endl;
				check = false;													//change check so that function loops again to ask for new input
				break;
			}
		}
		if (check == true)
			return atoi(s.c_str());												//if valid input returns user value
	}
}


/****************************************************************************************
** Function: signedInt()
** Description: Checks to make sure that user inputs an integer (positive or negative)
** Parameters: none
** Pre-conditions: none
** Post-conditions: returns an integer value
*****************************************************************************************/
int input::signedInt()
{
	check = false;																//loops until user enters a correct value
	while (check != true)
	{
		cin >> s;																//user input as string
		if (s.at(0) == '-') 
		{
			negNum++;
		}
		for (int i = 0; i < s.size(); i++)										//loops through user input to check each character 
		{
			if ((s.at(i) > 47 && s.at(i) < 58) || negNum > 0)						//checking if input is an integer by ascii value
			{
				check = true;
				negNum = 0;
			}
			else
			{
				cout << "Please enter an integer value: ";
				check = false;													//change check so that function loops again to ask for new input
				break;
			}
		}
		if (check == true)
			return atoi(s.c_str());												//if valid input returns user value
	}
}


/******************************************************************************************
** Function: checkDouble()
** Description: Checks user input to see if it is a valid double value
** Parameters: none
** Pre-conditions: none
** Post-conditions: returns user input in form of double
*******************************************************************************************/
double input::checkDouble()
{
	check = false;
	while (check != true)														//loop function until valid user input
	{
		decCount = 0;															//reset count of decimals after each loops
		cin >> s;											
		for (int i = 0; i < s.size(); i++)										//check each character in user input
		{
			if (s.at(i) > 47 && s.at(i) < 58)									//check that user input is an integer using ascii values
			{
				check = true;
			}
			else if (s.at(i) == '.')											//check if decimal value is part of input
			{
				decCount++;
				if (decCount > 1)												//if more than one decimal than input is invalid
				{
					check = false;
					cout << "Please enter a valid decimal number: ";
					break;
				}
			}
			else																//if input is another other than integer or decimal asks for new input
			{
				check = false;
				cout << "Please enter a positive value: ";
				break;
			}
		}
	}
	return atof(s.c_str());														//returns double value
}																				//thank god I'm done writing these comments. I should really do this while I'm coding the functions although i did get to listen to David Bowies new album some more (so good)