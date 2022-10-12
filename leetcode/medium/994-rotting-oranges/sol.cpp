/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 994 - Rotting Oranges
 * @approach Using a BFS approach, where rotten fruits rn, cause changes to
 * fruits in the next timestep through BFS
 * @date 12-10-2022
 *
 * Runtime - 13 ms O(m * n)
 * Memory Usage - 13.4 MB O(m * n)
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// void printGrid(vector<vector<int>> &grid) {

//   cout << "Printing grid" << endl;
//   for (int i = 0; i < grid.size(); i++) {
//     for (int j = 0; j < grid[0].size(); j++) {
//       printf("%d\t", grid[i][j]);
//     }

//     cout << endl;
//   }

//   cout << "Finished grid" << endl;
// }

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    // go through all positions and add fruit to queue if fruit is rotten there
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // add to queue if fruit is rotten at current position
        if (grid[i][j] == 2) {
          q.push({i, j});
          visited[i][j] = true;
        }

        if (grid[i][j] == 0) {
          visited[i][j] = true;
        }
      }
    }

    int currTime = 0;
    int currRow, currCol;

    while (!q.empty()) {
      vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

      // perform BFS for all currently added rotten fruits
      for (int i = q.size(); i > 0; i--) {
        // get the row and column at this time step
        tie(currRow, currCol) = q.front();
        q.pop();

        for (auto dir : dirs) {
          int newRow = currRow + dir.first, newCol = currCol + dir.second;

          // if new row and new col is valid, not visited, and has a fresh fruit
          // at that position
          if (newRow != -1 && newCol != -1 && newRow != m && newCol != n &&
              !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
            grid[newRow][newCol] = 2;
            visited[newRow][newCol] = true;
            q.push({newRow, newCol});
          }
        }
      }

      currTime++;
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) return -1;
      }
    }

    if (!currTime) return currTime;
    return currTime - 1;
  }
};
