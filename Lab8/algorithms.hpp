/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         11/22/2019
** Description:  This program contains the specification for the simple search,
** sort, and binary search algorithms. It also contains a function to read the
** file contents into a vector.
*******************************************************************************/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "inputValidation.hpp"

class algorithms
{
private:

public:
	algorithms() {};
	~algorithms() {};
	void readfilesIn(std::vector<int> &vecIn, std::string fileIn);
	void simpleSearch(int usernumIn, std::vector<int> &vecIn);
	void sort(std::ofstream& output, std::vector<int>& unsortvecIn);
	void binarySearch(int usernumIn, std::vector<int>& sortedvecIn);
};

#endif