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

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // go through matrix and add all 0 positions to the queue
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          q.push({i, j});
          visited[i][j] = true;
        }
      }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int currRow, currCol;
    while (!q.empty()) {
      tie(currRow, currCol) = q.front();
      q.pop();

      // all positions adjacent to the current one, will have minimum distance
      // one more than the already computed distance for the current one
      for (auto dir : dirs) {
        int newRow = currRow + dir.first, newCol = currCol + dir.second;

        if (newRow != -1 && newCol != -1 && newRow != m && newCol != n &&
            !visited[newRow][newCol]) {
          mat[newRow][newCol] = 1 + mat[currRow][currCol];
          visited[newRow][newCol] = true;

          q.push({newRow, newCol});
        }
      }
    }

    return mat;
  }
};