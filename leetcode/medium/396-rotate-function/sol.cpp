#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();

    int currF = 0,
        // calculates sum of all elements
        sum = 0;
    for (int i = 0; i < n; i++) {
      currF += i * nums[i];

      sum += nums[i];
    }

    int maxF = currF;
    if (n == 1) return maxF;

    for (int i = n - 1; i > 0; i--) {
      currF = currF - ((n - 1) * nums[i]) + sum - nums[i];

      maxF = max(maxF, currF);
    }

    return maxF;
  }
};