/**
 * @file rec-set.cpp
 * @author Vortexx2
 * @brief Problem 491 - Non-decreasing Subsequences
 * @date 21-01-2023
 * 
 * Runtime - 73 ms
 * Memory Usage - 22.2 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  set<vector<int>> res;

  void rec(int pos, vector<int> &nums, vector<int> &path) {
    if (pos == nums.size()) {
      if (path.size() >= 2) res.insert(path);
      return;
    }

    if (path.empty() || path[path.size() - 1] <= nums[pos]) {
      path.push_back(nums[pos]);
      rec(pos + 1, nums, path);
      path.pop_back();
    }

    rec(pos + 1, nums, path);
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    res = {};
    vector<int> path = {};
    rec(0, nums, path);

    return vector(res.begin(), res.end());
  }
};