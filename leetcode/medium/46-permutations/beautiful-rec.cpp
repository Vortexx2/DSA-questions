/**
 * @file beautiful-rec.cpp
 * @author Vortexx2
 * @brief Problem 46 - Permutations
 * @approach using a simple swapping approach
 * @date 15-10-2022
 * 
 * Runtime - 5 ms O(n !)
 * Memory Usage - 7.4 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    helper(nums, 0, res);

    return res;
  }

  void helper(vector<int> &nums, int start, vector<vector<int>> &res) {
    if (start == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);

      helper(nums, start + 1, res);

      swap(nums[i], nums[start]);
    }
  }
};