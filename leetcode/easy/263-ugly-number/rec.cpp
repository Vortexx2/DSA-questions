/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 263 - Ugly Number
 * @approach - Recursive approach (this problem does not require DP since we
 * aren't figuring out if multiple numbers are ugly or not)
 * @date 27-07-2022
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 6.1 MB O(n) stack memory
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<int, bool> dp;  // maps number to if it is ugly number or not
  vector<int> factors = {2, 3, 5};

  bool isUgly(int n) {
    if (n <= 0) return false;
    return recursive(n);
  }

  bool recursive(int n) {
    if (n == 1) return true;

    for (int factor : factors) {
      if (n % factor == 0) {
        if (recursive(n / factor)) return true;
      }
    }

    return false;
  }
};