/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 139 - Word Break
 * @approach Using a tabular bottom up DP approach for solving the problem
 * according to the second solution in the TechDose YT video -
 * https://www.youtube.com/watch?v=th4OnoGasMU
 * @date 13-07-2022
 *
 * Runtime - 69 ms O(n^3)
 * Memory Usage - 14.9 MB O(n^2)
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<string, bool>
      dict;  // map to store all words in dictionary for constant time lookup

  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();  // length of given string

    // dp 2 dimensional array. [i][j] stores if substring from i: (j + 1) is a
    // valid combination of dictionary words (subproblem), where upper bound (j
    // + 1) is not included
    vector<vector<bool>> table(n, vector<bool>(n, false));
    populateMap(wordDict);

    // outermost loop loops over all possible window sizes
    for (int windowSize = 0; windowSize < n; windowSize++) {
      // start of sliding window
      int windowStart = 0,
          // end of sliding window, [0, 0] indicates 1 character window
          windowEnd = windowStart + windowSize;

      while (windowEnd < n) {
        // if the whole substring is a valid word, don't need to check if it is
        // a composition of smaller words
        if (isValidWord(s.substr(windowStart, windowSize + 1))) {
          table[windowStart][windowEnd] = true;
        }

        else {
          table[windowStart][windowEnd] = false;

          // this loops checks all partitions for valid sub words
          // [0: 0][1: end], [0: 1][2: end] ... all such partitions are checked
          // for valid sub words

          for (int i = windowStart; i < windowEnd; i++) {
            if (table[windowStart][i] && table[i + 1][windowEnd]) {
              table[windowStart][windowEnd] = true;
              break;
            }
          }
        }

        windowStart++;
        windowEnd++;
      }
    }

    return table[0][n - 1];
  }

  // populates dictionary with all words in the `wordDict`, so as to have access
  // in constant time to all dictionary words
  void populateMap(vector<string>& dictArr) {
    dict.insert({"", true});
    for (string& s : dictArr) {
      dict.insert({s, true});
    }
  }

  // checks if given word is a provided word
  bool isValidWord(string word) { return dict.find(word) != dict.end(); }
};