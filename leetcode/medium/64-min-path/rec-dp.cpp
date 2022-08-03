/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 64 - Minimum Path Sum
 * @approach Recursive DP approach
 * @date 03-08-2022
 * 
 * Runtime - 8ms
 * Memory Usage - 10.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> dp;
  int minPathSum(vector<vector<int>>& grid) {
    dp.resize(grid.size(), vector<int>(grid[0].size(), -1));
    return helper(grid, 0, 0);
  }

  int helper(vector<vector<int>>& grid, int row, int col) {
    if (row == grid.size() - 1 && col == grid[0].size() - 1)
      return grid[row][col];

    if (dp[row][col] != -1) return dp[row][col];

    if (row == grid.size() - 1)
      dp[row][col] = grid[row][col] + helper(grid, row, col + 1);

    else if (col == grid[0].size() - 1)
      dp[row][col] = grid[row][col] + helper(grid, row + 1, col);

    else
      dp[row][col] = grid[row][col] + min(helper(grid, row + 1, col),
                                          helper(grid, row, col + 1));

    return dp[row][col];
  }
};