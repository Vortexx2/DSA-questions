/**
 * @file bst.cpp
 * @author Vortexx2
 * @brief Problem 74 - Search a 2D Matrix
 * @approach Using a BST type approach
 * @date 22-10-2022
 * 
 * Runtime - 3 ms O(log(m) + log(n))
 * Memory Usage - 9.6 MB O(1)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  // using a BST type approach.
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int row = 0, col = cols - 1;

    while (row < rows && col >= 0) {
      int currNum = matrix[row][col];
      if (currNum == target)
        return true;

      // considering numbers on the left are lesser than current number
      else if (target < currNum)
        col -= 1;

      // numbers on the below are greater than current number
      else
        row += 1;
    }

    return false;
  }
};