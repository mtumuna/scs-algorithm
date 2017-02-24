#include "scs-algorithm.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

std::string scsAlgorithm(const std::vector<std::string>& strList)
{
    std::map<char, int> rptList;     // Keeps track of how many times each letter has appeared.
	std::string solution;
	for (auto itr = strList.begin(); itr != strList.end(); ++itr)
	{
		std::cerr << *itr << "\t";   // Debug - Prints the current string in the loop.
		std::string skiplist;        // Contains a list of letters that were processed out of order.
		if (itr + 1 == strList.end()) // Base case.
		{
			for (char c : *itr)
			{
				if (skiplist.find(c) == std::string::npos)
				{
					// max_element finds the character that has appeared the most thus far.
					char maxC = max_element(rptList.begin(), rptList.end(), pairComp)->first;
					while (rptList[c] < rptList[maxC])
					{
						solution += maxC;
						rptList[maxC] = 0;
						skiplist += maxC;
						maxC = max_element(rptList.begin(), rptList.end(), pairComp)->first;
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
			std::cerr << c << rptList[c] << " "; // Debug - Prints the current state of the repeat list.
		}

		for (char c : *itr)
		{
			if ((itr + 1)->find(c) == std::string::npos && // If a character in one string cannot be
			    skiplist.find(c) == std::string::npos)     // found in the next
			{
				char maxC = std::max_element(rptList.begin(), rptList.end(), pairComp)->first;
 				while (rptList[c] < rptList[maxC])
				{
					solution += maxC;
					rptList[maxC] = 0;
					skiplist += maxC;
					maxC = std::max_element(rptList.begin(), rptList.end(), pairComp)->first;
				}

				solution += c;
				rptList[c] = 0;
			}
		}
		std::cerr << std::endl << "\t" << solution << std::endl; // Debug - Print the current state of the solution.
	}

	return solution;
}

bool pairComp(const std::pair<char, int>& largest, const std::pair<char, int>& first)
{
	return largest.second < first.second;
}
