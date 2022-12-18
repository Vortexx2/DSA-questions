/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 47 - Permutations 2
 * @approach Using a recursive backtracking approach
 * @date 18-12-2022
 * 
 * Runtime - 7 ms O(n !)
 * Memory Usage - 9 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  // maps count of each element in array
  map<int, int> counter;

  int n;

  vector<vector<int>> permuteUnique(vector<int> &nums) {
    res = {};
    n = nums.size();

    for (int i = 0; i < n; i++) {
      counter[nums[i]] += 1;
    }

    vector<int> path = {};

    helper(nums, path);
    return res;
  }

  void helper(vector<int> &nums, vector<int> &path) {
    if (path.size() == n) {
      res.push_back(path);
      return;
    }

    for (auto it = counter.begin(); it != counter.end(); it++) {
      // if current count has become zero
      if (!it->second) continue;

      path.push_back(it->first);
      it->second--;

      helper(nums, path);

      path.pop_back();
      it->second++;
    }
  }
};