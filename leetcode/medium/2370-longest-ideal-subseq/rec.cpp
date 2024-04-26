/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 2370 - Longest Ideal Subsequence
 * @approach - Using recursive memoization
 * @date 26-04-2024
 *
 * Runtime - TLE (74 / 85 testcases passed) O(n^2) solution
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int k;
    unordered_map<pair<int, char>, int> dp;

    int longestIdealString(string s, int k) {
        this->k = k;
        dp = {};
        return rec(s, 0, ' ');
    }

    bool diffAccept(char curr, char prev) { return abs(curr - prev) <= k; }

    int rec(string &s, int i, char prev) {
        if (i == s.size()) return 0;

        if (dp[{i, prev}]) return dp[{i, prev}];

        int include = 0, notInclude = 0;

        if (prev == ' ' || diffAccept(s[i], prev)) {
            include = 1 + rec(s, i + 1, s[i]);
        }

        notInclude = rec(s, i + 1, prev);
        int res = max(notInclude, include);

        dp[{i, prev}] = res;

        return res;
    }
};