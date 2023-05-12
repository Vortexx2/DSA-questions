/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 73 - Set Matrix Zeros
 * @approach Using a map for rows and cols, to figure out which positions to fill
 * @date 12-05-2023
 * 
 * Runtime - 17 ms O(m * n)
 * Memory Usage - 13.3 MB O(numZeros)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    set<int> rowsToFill, colsToFill;

    int rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j]) continue;

        // element is 0
        rowsToFill.insert(i);
        colsToFill.insert(j);
      }
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (rowsToFill.find(i) != rowsToFill.end() ||
            colsToFill.find(j) != colsToFill.end())
          matrix[i][j] = 0;
      }
    }
  }
};