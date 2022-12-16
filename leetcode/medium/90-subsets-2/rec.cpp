#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  vector<int> path;

  int size;

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    res = {};
    path = {};

    size = nums.size();

    sort(nums.begin(), nums.end());

    rec(nums, 0);

    return res;
  }

  void rec(vector<int>& nums, int idx) {
    if (idx == size - 1) {
      path.push_back(nums[idx]);
      res.push_back(path);
      path.pop_back();

      res.push_back(path);
      return;
    }

    // include current num
    path.push_back(nums[idx]);
    rec(nums, idx + 1);
    path.pop_back();

    // go forward till duplicate character does not occur again
    while (idx < size - 1 && nums[idx] == nums[idx + 1]) idx++;

    // if we reach the last index, add current path to res
    if (idx >= size - 1) {
      res.push_back(path);
      return;
    }

    rec(nums, idx + 1);
  }
};