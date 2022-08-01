/**
 * @file presum.cpp
 * @author Vortexx2
 * @brief Problem 304 - Range Sum Query 2D
 * @approach Computing the presum before all of the queries
 * @date 01-08-2022
 * 
 * Runtime - 769 ms
 * Memory Usage - 142.6 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
 public:
  int numRows, numCols;
  vector<vector<int>> preSum;
  NumMatrix(vector<vector<int>>& matrix) {
    numRows = matrix.size(), numCols = matrix[0].size();

    preSum.resize(numRows + 1, vector<int>(numCols + 1));

    for (int i = 1; i <= numRows; i++) {
      for (int j = 1; j <= numCols; j++) {
        preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] -
                       preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] -
           preSum[row1][col2 + 1] + preSum[row1][col1];
  }
};
