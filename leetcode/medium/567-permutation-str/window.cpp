/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 567 - Permutation in String
 * @approach Using a sliding window approach
 * @date 08-10-2022
 * 
 * Runtime - 46 ms O(n)
 * Memory Usage - 9.1 MB O(n)
 */
#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    if (n2 < n1) return false;

    // maps character to number of occurences in `s1`
    map<char, int> countMap;

    for (char c : s1) {
      countMap[c] += 1;
    }

    int l = 0, r = 0;

    // go through first n1 - 1 characters and compute the new count required for each character 
    while (r < n1 - 1) {
      if (countMap[s2[r]] == 1)
        countMap.erase(s2[r]);

      else
        countMap[s2[r]] -= 1;

      r++;
    }

    // start sliding window after that
    while (r < n2) {
      if (countMap[s2[r]] == 1)
        countMap.erase(s2[r]);

      else
        countMap[s2[r]]--;

      if (countMap.empty()) return true;

      if (countMap[s2[l]] == -1)
        countMap.erase(s2[l]);
      else
        countMap[s2[l]]++;

      r++;
      l++;
    }

    return countMap.empty();
  }
};