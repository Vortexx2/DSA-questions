/**
 * @file iter-bfs.cpp
 * @author Vortexx2
 * @brief Problem 733 - Flood Fill
 * @date 09-10-2022
 *
 * Runtime - 15 ms O(m * n)
 * Memory Usage - 14.2 MB O(1)
 */
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int startColor;
  int color;
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    if (image[sr][sc] == color) return image;
    int startColor = image[sr][sc];

    int rows = image.size(), cols = image[0].size();

    queue<pair<int, int>> q;
    q.push({sr, sc});

    int currRow, currCol;

    while (!q.empty()) {
      tie(currRow, currCol) = q.front();
      q.pop();

      if (currRow == -1 || currRow == rows || currCol == -1 || currCol == cols)
        continue;

      if (image[currRow][currCol] != startColor) continue;

      image[currRow][currCol] = color;

      q.push({currRow - 1, currCol});
      q.push({currRow + 1, currCol});
      q.push({currRow, currCol - 1});
      q.push({currRow, currCol + 1});
    }

    return image;
  }
};