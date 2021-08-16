/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 96 - Unique BSTs
 * @date 16-08-2021
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.1 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    vector<int> dp(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
      dp[i] = 0;
      for (int j = 0; j < i; j++)
        dp[i] += dp[j] * dp[i - j - 1];
    }

    return dp[n];
  }
};