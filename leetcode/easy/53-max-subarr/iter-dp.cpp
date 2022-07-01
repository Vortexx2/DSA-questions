#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    return maxInArr(dp);
  }

  int maxInArr(vector<int> &nums) {
    int maxVal = INT_MIN;
    for (int &num: nums) {
      maxVal = max(maxVal, num);
    }

    return maxVal;
  }
};