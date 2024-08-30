/**
 * @file dp-sol.cpp
 * @author Vortexx2
 * @brief Problem 312 - Burst Balloons
 *
 * @approach Using a 2D DP solution
 * Runtime - 192 ms O(n ^ 3)
 * Memory Usage - 12.36 MB O(n ^ 2)
 * @date 2024-08-30
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        return solve(nums, 1, n);
    }

    int solve(vector<int>& nums, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int curr_max = INT_MIN;
        for (int i = l; i <= r; i++) {
            int curr_coins = nums[l - 1] * nums[i] * nums[r + 1];
            curr_coins += solve(nums, l, i - 1) + solve(nums, i + 1, r);

            curr_max = max(curr_max, curr_coins);
        }

        dp[l][r] = curr_max;
        return curr_max;
    }
};