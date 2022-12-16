/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 78 - Subsets
 * @approach Using a DFS backtracking approach
 * @date 16-12-2022
 * 
 * Runtime - 4 ms O(2 ^ n)
 * Memory Usage - 10.7 MB O(2 ^ n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  int size;

  vector<vector<int>> subsets(vector<int>& nums) {
    res = {};
    vector<int> path = {};

    size = nums.size();

    rec(nums, 0, path);

    return res;
  }

  void rec(vector<int>& nums, int idx, vector<int>& path) {
    if (idx == size - 1) {
      res.push_back(path);
      path.push_back(nums[idx]);
      res.push_back(path);
      path.pop_back();

      return;
    }

    // first don't include current
    rec(nums, idx + 1, path);

    path.push_back(nums[idx]);
    rec(nums, idx + 1, path);
    path.pop_back();
  }
};