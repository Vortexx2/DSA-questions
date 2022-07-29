/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 931 - Minimum Falling Path
 * @approach - Using a recursive DP approach
 * @date 29-07-2022
 *
 * Runtime - 126 ms
 * Memory Usage - 16.2 MB
 */
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<pair<int, int>, int> dp;
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int minVal = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
      minVal = min(minVal, helper(matrix, 0, i));

    return minVal;
  }

  int helper(vector<vector<int>>& matrix, int row, int col) {
    if (col == -1) return INT_MAX;

    if (col == matrix.size()) return INT_MAX;

    if (row == matrix.size() - 1) return matrix[row][col];

    if (dp.find({row, col}) != dp.end()) return dp[{row, col}];

    dp[{row, col}] =
        matrix[row][col] + min(helper(matrix, row + 1, col - 1),
                               min(helper(matrix, row + 1, col),
                                   helper(matrix, row + 1, col + 1)));

    return dp[{row, col}];
  }
};