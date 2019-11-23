/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         9/29/2019
** Description:  This program contains the specification for integer input validation
** function. It contains two overloads of the function - one includes parameters for the
** min and max permissible values. The function converts the initial input from a string
** to integer format. It takes in an int by reference, a string, and two ints for min and
** max as parameters.
*******************************************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>

void inputValidation(int& userInt, std::string errorMsg);

void inputValidation(int& userInt, std::string errorMsg, int minVal, int maxVal);

#endif
