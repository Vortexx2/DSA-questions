/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 1406 - Stone Game 3
 * @approach Using recursive DP approach
 * @date 28-05-2023
 * 
 * Runtime - 867 ms O(n)
 * Memory Usage - 239.6 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> s;
  unordered_map<int, int> dp;

  int helper(int l) {
    if (l >= s.size()) return 0;

    if (dp.find(l) != dp.end()) return dp[l];

    int ans = INT_MIN;

    // take only one element
    ans = max(ans, s[l] - helper(l + 1)); 

    // take two elements
    if (l + 1 < s.size()) ans = max(ans, s[l] + s[l + 1] - helper(l + 2));

    // take three elements
    if (l + 2 < s.size()) ans = max(ans, s[l] + s[l + 1] + s[l + 2] - helper(l + 3));

    dp[l] = ans;
    return ans;
  }

  string stoneGameIII(vector<int>& stones) {
    s = stones;

    int alice = helper(0);

    if (alice > 0) return "Alice";
    
    if (alice < 0) return "Bob";

    return "Tie";
  }
};