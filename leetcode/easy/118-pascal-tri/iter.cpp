/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 118 - Pascal Triangle
 * @approach - Iterative Approach
 * @date 28-07-2022
 *
 * Runtime - 0 ms O(n ^ 2)
 * Memory Usage - 6.6 MB O(1) 0 additional memory used
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);

    for (int rowNum = 0; rowNum < numRows; rowNum++) {
      vector<int> row(rowNum + 1, 1);

      for (int i = 1; i < rowNum; i++) {
        row[i] = res[rowNum - 1][i - 1] + res[rowNum - 1][i];
      }

      res[rowNum] = row;
    }

    return res;
  }
};