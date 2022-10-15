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