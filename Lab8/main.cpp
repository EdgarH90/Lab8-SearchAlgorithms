/*******************************************************************************************
** Author: Edgar Hernandez
** Creation Date: 11/20/2019
** Description: This program reads in values from four separate text files into an array of 
** vectors. The program then runs simple search, sort, and binary search algorithms on each
** vector.
********************************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <climits>
#include "inputValidation.hpp"
#include "algorithms.hpp"


int main()
{
	//Create variables for input & output file names, the array of vectors,
	//the user integer selection, and the algorithm object.
	std::string outputFileName;
	std::string errorMsg = "Please enter a valid integer >= 0. ";
	std::string fileNames[4] = { "num.txt","early.txt","mid.txt","end.txt" };
	std::string userfileNames[4] = {"","","",""};
	std::vector<int> textfilesVect[4];
	int usersearchNum= 0;
	algorithms algoObj;
	
	//Load all the files into an array of vectors
	for (int i = 0; i < 4; i++)
	{
		algoObj.readfilesIn(textfilesVect[i], fileNames[i]);
	}

	//Prompt user for the number that they would like to search for
	std::cout << "Please enter the integer you would like to search for. " << std::endl;
	inputValidation(usersearchNum, errorMsg, 0, INT_MAX);
	
	//Search for the user's value in all four vectors in the array using the simple search algorithm
	for (int i = 0; i < 4; i++)
	{
		std::cout << fileNames[i] << ": ";
		algoObj.simpleSearch(usersearchNum, textfilesVect[i]);
		std::cout << std::endl;
	}

	//Sort the values in each vector and ouput to user's choice of file
	for (int i = 0; i < 4; i++)
	{
		//Prompt user for output file name
		std::cout << "Enter the name for output file number " << i+1 << " (do not include extension): " << std::endl;
		std::getline(std::cin, outputFileName);
		userfileNames[i] = outputFileName+".txt";
		std::ofstream outputFile(outputFileName+".txt", std::ios::app);

		algoObj.sort(outputFile, textfilesVect[i]);
		std::cout << std::endl;
	}

	//Display the sorted vectors for each file
	for (int i = 0; i < 4; i++)
	{
		std::cout << userfileNames[i] << ": " << std::endl;
		for (unsigned j = 0; j < textfilesVect[i].size(); j++)
		{
			std::cout << textfilesVect[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//Prompt user for the number that they would like to search for
	std::cout << "Please enter the integer you would like to search for. " << std::endl;
	inputValidation(usersearchNum, errorMsg, 0, INT_MAX);

	//Search for the user's value in all four vectors in the array using the binary search algorithm
	for (int i = 0; i < 4; i++)
	{
		std::cout << fileNames[i] << ": ";
		algoObj.binarySearch(usersearchNum, textfilesVect[i]);
		std::cout << std::endl;
	}

	return 0;
}