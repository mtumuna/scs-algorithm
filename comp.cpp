/*
 * Shortest Concatenating String
 * By Moses Tumuna
 *
 * Algorithm to find the shortest concatenating string from a list of strings.
 * Program can read strings from a text file (hardcoded for now) or get the
 * list from console input.
 *
 * Note: Requires C++ 11
 */

#include "scs-algorithm.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

int main()
{
	//
	// Data Acquisition
	//
	std::vector<std::string> strList;
	std::string temp;

	std::ifstream compFile ("comp.txt");
	if (compFile.is_open())
	{
		while (std::getline(compFile, temp))
		{
			strList.push_back(temp);
		}
	}
	else
	{
		std::stringstream ss;

		std::cout << "Enter a list of strings separated by spaces." << std::endl;
		std::getline(std::cin, temp);
		ss << temp;
		while (std::getline(ss, temp, ' '))
		{
			strList.push_back(temp);
		}
	}

	std::cout << std::endl << "Result: " << scsAlgorithm(strList);

	return 0;
}
