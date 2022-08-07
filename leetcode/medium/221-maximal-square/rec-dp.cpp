/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 221 - Maximal Square
 * @approach Recursive DP top down approach
 * @date 07-08-2022
 * 
 * Runtime - 143 ms
 * Memory Usage - 18.2 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // maps position to the largest square with top left as the current position
  vector<vector<int>> dp;
  int maximalSquare(vector<vector<char>>& matrix) {
    dp.resize(matrix.size(), vector<int>(matrix[0].size(), -1));

    int maxSide = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        maxSide = max(maxSide, helper(matrix, i, j));
      }
    }

    return maxSide * maxSide;
  }

  int helper(vector<vector<char>>& matrix, int row, int col) {
    // if topLeft pos has 0, that means that largest square possible with top
    // left as 0 is 0
    if (matrix[row][col] == '0') return 0;

    if (row == matrix.size() - 1 || col == matrix[0].size() - 1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    dp[row][col] = 1 + min(helper(matrix, row + 1, col),
                           min(helper(matrix, row, col + 1),
                               helper(matrix, row + 1, col + 1)));

    return dp[row][col];
  }
};