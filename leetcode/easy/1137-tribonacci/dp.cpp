/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 1137 - Nth Tribonacci Number
 * @date 26-06-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> seq = {0, 1, 1};
  int tribonacci(int n) {
    if (n <= 2) return seq[n];

    return helper(n);
  }

  int helper(int n) {
    if (n < seq.size()) return seq[n];

    seq.push_back(helper(n - 1) + helper(n - 2) + helper(n - 3));
    return seq[n];
  }
};