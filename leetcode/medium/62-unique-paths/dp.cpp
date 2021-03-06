/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 62 - Unique Paths
 * @date 30-07-2021
 * 
 * Runtime - 0 ms O(m * n)
 * Memory Usage - 6.5 MB O(m * n)
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
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};