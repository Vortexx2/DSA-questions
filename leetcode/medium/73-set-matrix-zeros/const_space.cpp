/**
 * @file const_space.cpp
 * @author Vortexx2
 * @brief Problem 73 - Set Matrix Zeros
 * @approach Using constant space
 * @date 12-05-2023
 * 
 * Runtime - 16 ms O(m * n)
 * Memory Usage - 13.2 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();

    bool rowZeros = false, colZeros = false;
    for (int i = 0; i < cols; i++) {
      if (!matrix[0][i]) {
        rowZeros = true;
        break;
      }
    }

    for (int i = 0; i < rows; i++) {
      if (!matrix[i][0]) {
        colZeros = true;
        break;
      }
    } 

    for (int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++) {
        if (!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = rows - 1; i >= 1; i--) {
      for (int j = cols - 1; j >= 1; j--) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
      }
    }

    if (rowZeros) {
      for (int i = 0; i < cols; i++) matrix[0][i] = 0;
    }
    if (colZeros) {
      for (int i = 0; i < rows; i++) matrix[i][0] = 0;
    }
  }
};