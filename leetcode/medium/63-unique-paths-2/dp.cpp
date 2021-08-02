/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Unique Paths II
 * @date 31-07-2021
 * 
 * Runtime - 3 ms
 * Memory Usage - 7.8 MB
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
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
    if (obstacleGrid[rows - 1][cols - 1])
      return 0;
    vector<vector<int>> dp(rows, vector<int>(cols, 1));

    bool found = false;
    for (int i = cols - 1; i >= 0; i--)
    {
      if (found || obstacleGrid[rows - 1][i])
      {
        found = true;
        dp[rows - 1][i] = 0;
      }
    }

    found = false;
    for (int i = rows - 1; i >= 0; i--)
    {
      if (found || obstacleGrid[i][cols - 1])
      {
        found = true;
        dp[i][cols - 1] = 0;
      }
    }

    for (int i = rows - 2; i >= 0; i--)
    {
      for (int j = cols - 2; j >= 0; j--)
      {
        if (obstacleGrid[i][j])
          dp[i][j] = 0;

        else
        {
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
      }
    }

    return dp[0][0];
  }
};