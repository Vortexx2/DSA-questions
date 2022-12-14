/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 130 - Surrounded Regions
 * @approach Using a recursive DFS approach
 * @date 14-12-2022
 * 
 * Runtime - 41 ms O(n ^ 2)
 * Memory Usage - 32.9 MB O(n ^ 2) (Recursive stack)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int m, n;
  char X = 'X', O = 'O', TEMP = '1';
  char target, convertTo;

  void solve(vector<vector<char>>& board) {
    m = board.size(), n = board[0].size();

    // convert all O's connected to the border to 1

    target = O, convertTo = TEMP;

    checkBorders(board);

    // convert all interior O's to X's

    target = O, convertTo = X;

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dfs(board, i, j);
      }
    }

    // now convert all 1's to 0's

    target = TEMP, convertTo = O;

    checkBorders(board);
  }

  void checkBorders(vector<vector<char>>& board) {
    // for top most row
    for (int i = 0; i < n; i++) {
      dfs(board, 0, i);
    }

    // for bottom most row
    for (int i = 0; i < n; i++) {
      dfs(board, m - 1, i);
    }

    // for left most col
    for (int i = 0; i < n; i++) {
      dfs(board, i, 0);
    }

    // for right most col
    for (int i = 0; i < n; i++) {
      dfs(board, i, n - 1);
    }
  }

  void dfs(vector<vector<char>>& board, int row, int col) {
    if (row < 0 || row >= m || col < 0 || col >= n) return;

    if (board[row][col] != target) return;

    // current character is equal to target

    board[row][col] = convertTo;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto& d : dirs) dfs(board, row + d.first, col + d.second);
  }
};