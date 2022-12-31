/**
 * @file comb-sum-3.cpp
 * @author Vortexx2
 * @brief Problem 216 - Combination Sum 3
 * @date 31-12-2022
 *
 * Runtime - 0 ms
 * Memory Usage - 6.5 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  // vector<int> path;
  int k, n;

  vector<vector<int>> combinationSum3(int k, int n) {
    res = {};
    vector<int> path = {};
    this->k = k, this->n = n;
    helper(0, 0, path);

    return res;
  }

  void helper(int startIndex, int currSum, vector<int> &path) {
    if (path.size() == k && currSum == n) {
      res.push_back(path);
      return;
    }

    if (path.size() >= k || startIndex > 9) return;

    for (int i = startIndex + 1; i <= 9; i++) {
      path.push_back(i);
      helper(i, currSum + i, path);
      path.pop_back();
    }
  }
};