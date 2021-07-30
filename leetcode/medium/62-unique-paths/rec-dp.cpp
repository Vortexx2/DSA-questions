/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 62 - Unique Paths
 * @date 29-07-2021
 * 
 * Runtime - 4 ms
 * Memory Usage - 9 MB
 */
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    unordered_map<string, int> dp = {};

    return helper(m, n, dp);
  }

  int helper(int m, int n, unordered_map<string, int> &dp)
  {
    if (m == 0 || n == 0)
      return 0;
    if (m == 1 || n == 0)
      return 1;

    string key = to_string(m) + "," + to_string(n);
    auto itr = dp.find(key);

    if (itr != dp.end())
      return itr->second;

    dp[key] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    return dp[key];
  }
};