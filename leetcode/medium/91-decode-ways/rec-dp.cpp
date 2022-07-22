/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 91 - Decode Ways
 * @approach Recursive DP approach
 * @date 22-07-2022
 *
 * Runtime - 4 ms
 * Memory Usage - 6.5 MB
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  // dp is of size O(n) and maps index to number of ways to decode substring
  // start from current index
  map<int, int> dp;
  string inpStr;
  int numDecodings(string s) {
    inpStr = s;
    return recursive(0);
  }

  int charToInt(char digit) { return digit - '0'; }

  int recursive(int i) {
    if (dp.find(i) != dp.end()) return dp[i];

    // base case where we reach till the final index
    if (i == inpStr.size()) return 1;

    // no ways exist to decode substring which starts with "0"
    if (inpStr[i] == '0') return 0;

    // case where we take only 1 character in the current letter
    int res = recursive(i + 1);

    // case where taking 2 characters at a time is possible
    if (i + 1 < inpStr.size() &&
        (inpStr[i] == '1' ||
         (inpStr[i] == '2' && charToInt(inpStr[i + 1]) <= 6)))
      res += recursive(i + 2);

    dp[i] = res;
    return res;
  }
};
