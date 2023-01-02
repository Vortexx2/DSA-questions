/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 520 - Detect Capital
 * @date 02-01-2023
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 6.2 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() == 1) return true;

    bool firstCapital = isupper(word[0]);
    bool secondCapital = isupper(word[1]);

    if (!firstCapital && secondCapital) return false;

    for (int i = 2; i < word.size(); i++) {
      if (!firstCapital && isupper(word[i])) return false;

      if (firstCapital && secondCapital && islower(word[i])) return false;

      if (firstCapital && !secondCapital && isupper(word[i])) return false;
    }

    return true;
  }
};