/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 40 - Combinations 2
 * @appraoch Using a counter with backtracking recursively
 * @date 19-12-2022
 * 
 * Runtime - 4 ms O(N ^ 2)
 * Memory Usage - 11 MB O(N)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  int n;
  map<int, int> counter;
  vector<int> path;

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    res = {};
    path = {};
    n = candidates.size();

    sort(candidates.begin(), candidates.end());

    // increment counter for candidate by 1
    for (int i = 0; i < n; i++) {
      counter[candidates[i]]++;
    }

    helper(candidates, target, counter.begin());

    return res;
  }

  void helper(vector<int>& candidates, int target,
              map<int, int>::iterator start) {
    if (target < 0) return;

    if (!target) {
      res.push_back(path);
      return;
    }

    for (auto it = start; it != counter.end(); it++) {
      // if count for num is more than 0
      // since counter is ordered map
      if (it->second) {
        if (it->first > target) return;

        path.push_back(it->first);
        it->second--;

        helper(candidates, target - it->first, it);

        path.pop_back();
        it->second++;
      }
    }
  }
};