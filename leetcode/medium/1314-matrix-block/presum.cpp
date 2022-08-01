/**
 * @file presum.cpp
 * @author Vortexx2
 * @brief Problem 1314 - Matrix Block Sum
 * @approach Using a precomputation
 * @date 01-08-2022
 * 
 * m is number of rows, n is number of columns
 * Runtime - 11 ms O(m * n) 
 * Memory Usage - 9.5 MB O(m * n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    auto prefixSum = constructPrefixSum(mat);

    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        // the top left coordinate (1 indexed), restricted to range (1, 1) to
        // (m, n)
        pair<int, int> topLeft = {max(0, row - k) + 1, max(0, col - k) + 1};

        // the bottom right coordinate (1 indexed), restricted to range (1, 1)
        // to (m, n)
        pair<int, int> bottomRight = {min(m - 1, row + k) + 1,
                                      min(n - 1, col + k) + 1};

        int area = prefixSum[bottomRight.first][bottomRight.second] -
                   prefixSum[topLeft.first - 1][bottomRight.second] -
                   prefixSum[bottomRight.first][topLeft.second - 1] +
                   prefixSum[topLeft.first - 1][topLeft.second - 1];

        ans[row][col] = area;
      }
    }

    return ans;
  }

  /**
   * @brief Computes the `preSum` which is the area of the rectangle from the
   * origin to the current position. Can be used to calculate sub squares in the
   * original matrix by some more calculations.
   *
   * @param mat matrix on which we will compute the presum.
   * @return vector<vector<int>> the presum. `preSum[i][j]` represents the of
   * the rectangle in the original matrix `mat` from (0, 0) to (i - 1, j - 1)
   */
  vector<vector<int>> constructPrefixSum(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1));

    for (int row = 0; row < m; row++) {
      for (int col = 0; col < n; col++) {
        prefixSum[row + 1][col + 1] = prefixSum[row][col + 1] +
                                      prefixSum[row + 1][col] -
                                      prefixSum[row][col] + mat[row][col];
      }
    }

    return prefixSum;
  }
};