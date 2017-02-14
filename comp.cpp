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

#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

// Comparator function to compare the integer of a char-int pair. Used as the
// comparator for the max_element algorithm.
bool elemComp(const pair<char, int>& largest, const pair<char, int>& first)
{
	return largest.second < first.second;
}

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

	//
	// SCS Algorithm
	//
	map<char, int> rptList;     // Keeps track of how many times each letter has appeared.
	string solution;
	for (auto itr = probes.begin(); itr != probes.end(); ++itr)
	{
		cerr << *itr << "\t";   // Debug - Prints the current string in the loop.
		string skiplist;        // Contains a list of letters that were processed out of order.
		if (itr + 1 == probes.end()) // Base case.
		{
			for (char c : *itr)
			{
				if (skiplist.find(c) == string::npos)
				{
					// max_element finds the character that has appeared the most thus far.
					char maxC = max_element(rptList.begin(), rptList.end(), elemComp)->first;
					while (rptList[c] < rptList[maxC])
					{
						solution += maxC;
						rptList[maxC] = 0;
						skiplist += maxC;
						maxC = max_element(rptList.begin(), rptList.end(), elemComp)->first;
					}

					solution += c;
					rptList[c] = 0;
				}
			}
			break;
		}

		for (char c : *itr)
		{
			rptList[c] += 1;
			cerr << c << rptList[c] << " "; // Debug - Prints the current state of the repeat list.
		}

		for (char c : *itr)
		{
			if ((itr + 1)->find(c) == string::npos && // If a character in one string cannot be
			    skiplist.find(c) == string::npos)     // found in the next
			{
				char maxC = max_element(rptList.begin(), rptList.end(), elemComp)->first;
 				while (rptList[c] < rptList[maxC])
				{
					solution += maxC;
					rptList[maxC] = 0;
					skiplist += maxC;
					maxC = max_element(rptList.begin(), rptList.end(), elemComp)->first;
				}

				solution += c;
				rptList[c] = 0;
			}
		}
		cerr << endl << "\t" << solution << endl; // Debug - Print the current state of the solution.
	}

	cout << endl << "Result: " << solution;

	return 0;
}
