/**
 * @file bottom-up.cpp
 * @author Vortexx2
 * @brief Problem 2370 - Longest Ideal Subsequence
 * @approach Using a 1d DP array to keep track of the maximum subsequence
 * possible ending at a particular character
 * @date 26-04-2024
 *
 * Runtime - 27 ms O(n * k)
 * Memory Usage - 11.54 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int longestIdealString(string s, int k) {
        // construct a dp array with 0s for all alphabets
        // this will store the maximum possible subsequence ending at a
        // character for a particular iteration
        // (or current character which is being processed in the string)
        vector<int> dp(26, 0);

        for (auto &ch : s) {
            int curr = ch - 'a';
            int left = max(0, curr - k), right = min(25, curr + k);
            int largest = 0;

            for (int i = left; i <= right; i++) largest = max(largest, dp[i]);

            dp[curr] = max(largest + 1, dp[curr]);
        }

        int res = 0;
        for (auto val : dp) res = max(res, val);

        return res;
    }
};