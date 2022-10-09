/**
 * @file iter-dfs.cpp
 * @author Vortexx2
 * @brief Problem 733 - Flood Fill
 * @approach Using an iterative DFS approach
 * @date 09-10-2022
 * 
 * Runtime - 13 ms O(m * n)
 * Memory Usage - 14.3 MB
 */
#include <iostream>
#include <queue>
#include <stack>
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

    stack<pair<int, int>> st;
    st.push({sr, sc});

    int currRow, currCol;

    while (!st.empty()) {
      tie(currRow, currCol) = st.top();
      st.pop();

      if (currRow == -1 || currRow == rows || currCol == -1 || currCol == cols)
        continue;

      if (image[currRow][currCol] != startColor) continue;

      image[currRow][currCol] = color;

      st.push({currRow - 1, currCol});
      st.push({currRow + 1, currCol});
      st.push({currRow, currCol - 1});
      st.push({currRow, currCol + 1});
    }

    return image;
  }
};