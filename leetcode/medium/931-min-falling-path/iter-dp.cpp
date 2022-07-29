/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 931 - Minimum Falling Path
 * @approach - Iterative DP, bottom up approach
 * @date 29-07-2022
 * 
 * Runtime - 33 ms
 * Memory Usage - 10.2 MB
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    if (matrix.size() == 1) return matrix[0][0];

    vector<vector<int>> dp(matrix.size() - 1, vector<int>(matrix.size()));

    for (int row = matrix.size() - 2; row >= 0; row--) {
      for (int col = 0; col < matrix.size(); col++) {
        if (row == matrix.size() - 2) {
          dp[row][col] += matrix[row][col];

          if (col == 0) {
            dp[row][col] += min(matrix[row + 1][col], matrix[row + 1][col + 1]);
          }

          else if (col == matrix.size() - 1) {
            dp[row][col] += min(matrix[row + 1][col - 1], matrix[row + 1][col]);
          }

          else {
            dp[row][col] +=
                min(matrix[row + 1][col - 1],
                    min(matrix[row + 1][col], matrix[row + 1][col + 1]));
          }
        }

        else {
          dp[row][col] += matrix[row][col];

          if (col == 0) {
            dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
          }

          else if (col == matrix.size() - 1) {
            dp[row][col] += min(dp[row + 1][col - 1], dp[row + 1][col]);
          }

          else {
            dp[row][col] += min(dp[row + 1][col - 1],
                                min(dp[row + 1][col], dp[row + 1][col + 1]));
          }
        }
      }
    }

    int minVal = INT_MAX;
    for (int col = 0; col < matrix.size(); col++) {
      minVal = min(minVal, dp[0][col]);
    }

    return minVal;
  }
};