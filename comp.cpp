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
using namespace std;

int main()
{
	//
	// Data Acquisition
	//
	vector<string> probes;
	string temp;

	ifstream compFile ("comp.txt");
	if (compFile.is_open())
	{
		while (getline(compFile, temp))
		{
			probes.push_back(temp);
		}
	}
	else
	{
		stringstream ss;

		cout << "Enter a list of strings separated by spaces." << endl;
		getline(cin, temp);
		ss << temp;
		while (getline(ss, temp, ' '))
		{
			probes.push_back(temp);
		}
	}

	cout << endl << "Result: " << scsAlgorithm(probes);

	return 0;
}
