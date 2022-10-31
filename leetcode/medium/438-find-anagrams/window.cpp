/**
 * @file window.cpp
 * @author Vortexx2
 * @brief Problem 438 - Find All Anagrams In A String
 * @approach Using a sliding window approach
 * @date 31-10-2022
 *
 * Runtime - 9 ms O(n)
 * Memory Usage - 8.6 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int charToInt(char c) { return c - 'a'; }

  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) return {};

    vector<int> res;

    // counter for each letter in alphabet
    vector<int> pCount(26, 0), sCount(26, 0);

    // go through each character for length of matching string to see how many
    // match
    for (int i = 0; i < p.size(); i++) {
      sCount[charToInt(s[i])] += 1;
      pCount[charToInt(p[i])] += 1;
    }

    // number of matching letters in the counter
    int numMatches = 0;
    for (int i = 0; i < 26; i++) {
      if (sCount[i] == pCount[i]) numMatches++;
    }

    int l = 0, r = p.size() - 1;
    while (r < s.size()) {
      // if all letters match
      if (numMatches == 26) res.push_back(l);

      int currL = charToInt(s[l]);
      // decrement the previous start value by 1
      sCount[currL] -= 1;

      l++;
      r++;

      if (sCount[currL] == pCount[currL]) numMatches++;

      // decrement numMatches only when we were at the exact amount of current
      // letters but lose 1 by sliding the window
      else if (pCount[currL] - sCount[currL] == 1)
        numMatches--;

      if (r != s.size()) {
        int nextR = charToInt(s[r]);
        sCount[nextR] += 1;
        if (sCount[nextR] == pCount[nextR]) numMatches++;

        // similar logic from above applies here
        else if (sCount[nextR] - pCount[nextR] == 1)
          numMatches--;
      }
    }

    return res;
  }
};