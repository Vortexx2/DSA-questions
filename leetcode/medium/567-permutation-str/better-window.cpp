/**
 * @file better-window.cpp
 * @author Vortexx2
 * @brief Problem 567 - Permutation in String
 * @approach Using a vector to denote all possible characters in the string
 * @date 08-10-2022
 * 
 * Runtime - 9 ms O(n)
 * Memory Usage - 7.3 MB O(1)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int toInteger(char c) { return (c - 'a'); }

  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    if (n2 < n1) return false;

    vector<int> s1Count(26, 0), s2Count(26, 0);

    for (int i = 0; i < n1; i++) {
      s1Count[toInteger(s1[i])] += 1;
      s2Count[toInteger(s2[i])] += 1;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++) {
      if (s2Count[i] == s1Count[i]) matches += 1;
    }

    int l = 0, r = n1;
    while (r < n2) {
      if (matches == 26) return true;

      int index = toInteger(s2[r]);
      s2Count[index] += 1;

      if (s2Count[index] == s1Count[index])
        matches += 1;
      else if (s1Count[index] + 1 == s2Count[index])
        matches -= 1;

      index = toInteger(s2[l]);
      s2Count[index] -= 1;
      if (s2Count[index] == s1Count[index])
        matches += 1;
      else if (s2Count[index] == s1Count[index] - 1)
        matches -= 1;

      l++;
      r++;
    }

    return matches == 26;
  }
};