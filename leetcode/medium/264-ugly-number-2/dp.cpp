/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 264 - Ugly Number 2
 * @approach Recursive DP solution where we iterate from current ugly number to
 * the next number while constantly checking for the condition for it to be ugly.
 * @date 25-07-2022
 *
 * Runtime - Time Limit Exceeded
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  // maps number to if it is ugly or not
  map<int, bool> dp;
  int nthUglyNumber(int n) {
    int currUgly = 1, currIndex = 1;

    while (currIndex != n) {
      int findNext = currUgly + 1;
      while (!isUgly(findNext)) {
        findNext++;
      }

      currUgly = findNext;
      currIndex++;
    }

    return currUgly;
  }

  bool isUgly(int num) {
    if (dp.find(num) != dp.end()) return dp[num];

    if (num == 1) return true;

    bool res;

    for (int factor : {2, 3, 5}) {
      if (num % factor == 0) {
        if (isUgly(num / factor)) {
          dp[num] = true;
          return true;
        }
      }
    }

    dp[num] = false;
    return false;
  }
};