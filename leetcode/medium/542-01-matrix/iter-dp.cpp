/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 542 - 01 Matrix
 * @approach Using an iterative bottom up DP approach
 * @date 12-10-2022
 * 
 * Runtime - 120 ms O(m * n)
 * Memory Usage - 27.3 MB O(1)
 */
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int maxInt = 1e5;

    vector<vector<int>> res(m, vector<int>(n, 1e5));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          res[i][j] = 0;

        else {
          int left = j > 0 ? res[i][j - 1] : maxInt;
          int top = i > 0 ? res[i - 1][j] : maxInt;

          res[i][j] = min(left, top) + 1;
        }
      }
    }

    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int right = j < n - 1 ? res[i][j + 1] : maxInt;
        int bottom = i < m - 1 ? res[i + 1][j] : maxInt;

        res[i][j] = min(res[i][j], min(right, bottom) + 1);
      }
    }

    return res;
  }
};