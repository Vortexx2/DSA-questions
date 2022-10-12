/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 542 - 01 Matrix
 * @approach DFS
 * @date 12-10-2022
 * 
 * Runtime - TLE O( (m * n) ^ 2 )
 */
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxInt = 1e5;
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> res(m, vector<int>(n, maxInt));
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res[i][j] = helper(mat, i, j, visited);
      }
    }

    return res;
  }

  int helper(vector<vector<int>>& mat, int row, int col,
             vector<vector<bool>> visited) {
    if (row < 0 || col < 0 || row == mat.size() || col == mat[0].size() ||
        visited[row][col])
      return maxInt;

    if (mat[row][col] == 0) return 0;

    visited[row][col] = true;

    int minDist = maxInt;

    vector<pair<int, int>> posPairs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto posPair : posPairs) {
      int a = helper(mat, row + posPair.first, col + posPair.second, visited);

      minDist = min(minDist, a + 1);

      if (minDist == 1) break;
    }

    visited[row][col] = false;
    return minDist;
  }
};