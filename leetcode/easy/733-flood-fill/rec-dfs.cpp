/**
 * @file dfs.cpp
 * @author Vortexx2
 * @brief Problem 733 - Flood Fill
 * @approach Using simple DFS
 * @date 09-10-2022
 * 
 * Runtime - 15 ms O(m * n)
 * Memory Usage - O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int startColor;
  int color;
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    if (image[sr][sc] == color) return image;

    startColor = image[sr][sc];
    this->color = color;

    helper(image, sr, sc);
    return image;
  }

  void helper(vector<vector<int>>& image, int row, int col) {
    if (row < 0 || row >= image.size()) return;
    if (col < 0 || col >= image[0].size()) return;
    if (startColor == color || image[row][col] != startColor) return;

    image[row][col] = color;

    helper(image, row - 1, col);
    helper(image, row + 1, col);
    helper(image, row, col - 1);
    helper(image, row, col + 1);
  }
};