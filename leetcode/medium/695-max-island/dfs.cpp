/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 695 - Max Area Of Island
 * @approach Using a DFS approach and also remembering where we have been
 * @date 09-10-2022
 * 
 * Runtime - 28 ms
 * Memory Usage - 27.4 MB
 */
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<bool>> visited;
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    int rows = grid.size(), cols = grid[0].size();
    visited.resize(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 0 || visited[i][j]) continue;

        maxArea = max(maxArea, dfs(grid, i, j));
      }
    }

    return maxArea;
  }

  int dfs(vector<vector<int>>& grid, int startRow, int startCol) {
    int area = 0;

    int rows = grid.size(), cols = grid[0].size();

    stack<pair<int, int>> st;
    st.push({startRow, startCol});

    int currRow, currCol;

    while (!st.empty()) {
      tie(currRow, currCol) = st.top();
      st.pop();

      if (grid[currRow][currCol] == 0 || visited[currRow][currCol]) continue;

      area += 1;
      visited[currRow][currCol] = true;

      if (currRow != 0 && !visited[currRow - 1][currCol])
        st.push({currRow - 1, currCol});

      if (currRow != rows - 1 && !visited[currRow + 1][currCol])
        st.push({currRow + 1, currCol});

      if (currCol != 0 && !visited[currRow][currCol - 1])
        st.push({currRow, currCol - 1});

      if (currCol != cols - 1 && !visited[currRow][currCol + 1])
        st.push({currRow, currCol + 1});
    }

    return area;
  }
};