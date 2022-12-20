/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 79 - Word Search
 * @approach Using a recursive backtracking approach
 * @date 20-12-2022
 * 
 * Runtime - 699 ms
 * Memory Usage - 8.1 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int m, n;
  string w;
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  bool exist(vector<vector<char>>& board, string word) {
    m = board.size(), n = board[0].size();

    w = word;

    bool res;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        res = helper(board, i, j, 0);

        if (res) return true;
      }
    }

    return false;
  }

  bool helper(vector<vector<char>>& board, int row, int col, int curr) {
    if (curr == w.size()) return true;

    if (row < 0 || col < 0 || row >= m || col >= n) return false;

    if (board[row][col] != w[curr]) return false;

    // below code means current position has equal characters
    bool res;
    char temp = board[row][col];
    board[row][col] = '*';

    for (auto& d : dirs) {
      res = helper(board, row + d.first, col + d.second, curr + 1);

      if (res) {
        board[row][col] = temp;
        return true;
      }
    }

    board[row][col] = temp;
    return false;
  }
};