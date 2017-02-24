#ifndef SCS_ALGORITHM_H
#define SCS_ALGORITHM_H

#include <string>
#include <vector>
#include <utility>

std::string scsAlgorithm(const std::vector<std::string>& strList);

// Comparator function to compare the integer of a char-int pair. Used as the
// comparator for the max_element algorithm.
bool pairComp(const std::pair<char, int>& largest, const std::pair<char, int>& first);

#endif // SCS_ALGORITHM_H
