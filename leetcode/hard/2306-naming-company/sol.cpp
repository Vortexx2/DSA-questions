/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2306 - Naming a Company
 * @approach Used neetcode approach ( https://www.youtube.com/watch?v=NrHpgTScOcY )
 * @date 24-02-2023
 * 
 * Runtime - 1267 ms O(n)
 * Memory Usage - 86.7 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  long long distinctNames(vector<string>& ideas) {
    // maps character to suffix. Adds O(n) additional memory
    map<char, set<string>> wordMap;

    long long res = 0;

    // go through ideas and store in wordMap (word[0], suffix)
    for (auto& idea : ideas) {
      wordMap[idea[0]].insert(idea.substr(1, idea.size() - 1));
    }

    // iterate through all starting characters
    for (auto it = wordMap.begin(); it != wordMap.end(); it++) {
      // first set
      auto& ogSet = it->second;

      // we go through rest of the starting characters
      // valid words can only be made with other words have different starting
      // characters
      for (auto it2 = next(it, 1); it2 != wordMap.end(); it2++) {
        auto& otherSet = it2->second;

        int commonCount = 0;

        // go through each suffix in the otherSet and increment commonCount if
        // it exists in the original
        for (auto& suffix : otherSet) {
          if (ogSet.find(suffix) != ogSet.end()) commonCount++;
        }

        long ogUnique = ogSet.size() - commonCount,
             otherUnique = otherSet.size() - commonCount;

        res += 2 * ogUnique * otherUnique;
      }
    }

    return res;
  }
};