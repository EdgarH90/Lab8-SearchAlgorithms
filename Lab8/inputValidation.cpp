/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/12/2019
** Description:  This program contains the implementation for integer input validation
** function. It contains two overloads of the function - one includes parameters for the
** min and max permissible values. The function converts the initial input from a string
** to integer format. It takes in an int by reference, a string, and two ints for min and
** max as parameters.
*******************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

/*********************************************************************
*					void inputValidation(&int, string, int, int)
* This overload of the function takes in a reference to an int and a string as parameters.
* The function then converts the input into a valid integer.
*********************************************************************/

void inputValidation(int& userInt, std::string errorMsg)
{
	std::string userInput = "";
	bool inputStatus = 1;
	while (inputStatus)
	{
		std::getline(std::cin, userInput);

		//Converting the input to an integer
		//Used http://www.cplusplus.com/forum/articles/6046/ as resource
		std::stringstream myStream(userInput);
		if (myStream >> userInt)
		{
			if (!myStream.eof()) // Checking to see if there is data left in the input stream
			{
				std::cout << errorMsg << std::endl;
			}
			else
				inputStatus = 0;
		}
		else
		{
			std::cout << errorMsg << std::endl;
		}
	}
}

/*********************************************************************
*					void inputValidation(&int, string, int, int)
* This overload of the function takes in two additional ints for the minimum
* and maximum values as parameters.
*********************************************************************/

void inputValidation(int& userInt, std::string errorMsg, int minVal, int maxVal)
{
	std::string userInput = "";
	bool inputStatus = 1;
	while (inputStatus)
	{
		std::getline(std::cin, userInput);

		//Converting the input to an integer
		//Used http://www.cplusplus.com/forum/articles/6046/ as resource
		std::stringstream myStream(userInput);
		if (myStream >> userInt)
		{
			if (!myStream.eof()) // Checking to see if there is data left in the input stream
			{
				std::cout << errorMsg << std::endl;
			}
			else if ((userInt < minVal) || (userInt > maxVal)) // Checking to see if min or max is exceeded
				std::cout << errorMsg << std::endl;
			else
				inputStatus = 0;
		}
		else
		{
			std::cout << errorMsg << std::endl;
		}
	}
}

