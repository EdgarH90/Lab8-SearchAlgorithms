/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         11/22/2019
** Description:  This program contains the implementationn for the simple search,
** sort, and binary search algorithms. It also contains a function to read the
** file contents into a vector.
*******************************************************************************/
#include "algorithms.hpp"


/*********************************************************************
*					algorithms::readfilesIn()
* This function takes in a vector reference and a file name string as
* parameters and then writes the values from the file into the vector.
*********************************************************************/
void algorithms::readfilesIn(std::vector<int> &vecIn, std::string fileIn)
{
	//If the file does not exist, program terminates
	std::ifstream inputFile(fileIn, std::ios::in);
	if (inputFile.fail())
	{
		std::cout << "The file was not found. Program will now terminate." << std::endl;
	}
	else
	{
		//Get integers from file
		int numberIn = 0;
		while (inputFile >> numberIn)
		{
			vecIn.push_back(numberIn);
		}
		inputFile.close();
	}
}

/*********************************************************************
*					algorithms::simpleSearch()
* This function takes in a vector reference and an integer as parameters
* and then searches for the integer in the vector using a simple search
* algorithm.
*********************************************************************/
void algorithms::simpleSearch(int usernumIn, std::vector<int> &vecIn)
{
		//readfilesIn(vecIn, textFiles[i]);

		//Search for the value in the vector.
		//Used the code in Ch. 9 pg. 604 as reference
		bool found = false;
		int index = 0;
		int lastvecVal = vecIn.size(); //Used to get size of vector

		//Loop through all elements in vector
		while ((index < lastvecVal) && !found)
		{
			if (vecIn[index] == usernumIn)
			{
				found = true;
				std::cout << "target value found." << std::endl;
			}
			index++;
		}
		if (!found)
		{
			std::cout << "target value not found." << std::endl;
		}
		std::cout << std::endl;
}


/*********************************************************************
*					algorithms::sort()
* This function takes in a vector reference and an output file stream
* variable as parameters. The function sorts the vector values and then
* outputs them into the file chosen by the user.
*********************************************************************/
void algorithms::sort(std::ofstream& output, std::vector<int>& unsortvecIn)
{
	//Sort the values for the vector
	//Used the bubble sort code in Ch. 9 pg. 624 as reference
	int temp;
	bool swap;

	//Run algorithm until no more swaps can be made
	do
	{
		swap = false;
		for (unsigned i = 0; i < unsortvecIn.size()-1; i++)
		{
			//If current value is greater than next value, swap value positions
			if (unsortvecIn[i] > unsortvecIn[i + 1])
			{
				temp = unsortvecIn[i];
				unsortvecIn[i] = unsortvecIn[i + 1];
				unsortvecIn[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	//Write sorted vector to outputfile
	for (unsigned i = 0; i < unsortvecIn.size(); i++)
	{
		output << unsortvecIn[i] << " ";
	}
	std::cout << std::endl;
}


/*********************************************************************
*					algorithms::binarySearch()
* This function takes in a sorted vector reference and an integer as parameters
* and then searches for the integer in the vector using a binary search
* algorithm.
*********************************************************************/
void algorithms::binarySearch(int usernumIn, std::vector<int>& vecIn)
{
	//Used binary search in Ch. 9 pg. 607 as reference
	//Create variables for low, high, and midpoints
	int low = 0;
	int high = vecIn.size() - 1;
	int mid;
	bool found = false;

	//Loop through the vector
	while (!found && low <= high)
	{
		mid = (low + high) / 2;

		//Once value is in the midpoint, return value found 
		if (vecIn[mid] == usernumIn)
		{
			found = true;
			std::cout << "target value found." << std::endl;
		}
		//If midpoint is larger than value, set it as the new high
		else if (vecIn[mid] > usernumIn)
		{
			high = mid - 1;
		}
		//Otherwise, change the low to the previous midpoint plus one
		else
		{
			low = mid + 1;
		}
	}
	if (!found)
	{
		std::cout << "target value not found." << std::endl;
	}
}