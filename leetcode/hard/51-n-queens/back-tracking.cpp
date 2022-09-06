/**
 * @file back-tracking.cpp
 * @author Vortexx2
 * @brief Problem 51 - N Queens
 * @approach Backtracking
 * @date 06-09-2022
 * 
 * Runtime - 127 ms
 * Memory Usage - 50.7 MB
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> ans;
  vector<vector<string>> solveNQueens(int n) {
    // allocate '.' for each empty position (n times)
    vector<string> board(n, string(n, '.'));

    helper(board, 0);
    return ans;
  }

  void helper(vector<string> board, int col) {
    int n = board.size();
    if (col >= n) {
      ans.push_back(board);
      return;
    }

    for (int row = 0; row < n; row++) {
      if (isSafe(board, row, col)) {
        board[row][col] = 'Q';

        helper(board, col + 1);

        board[row][col] = '.';
      }
    }
  }

  bool isSafe(vector<string> board, int row, int col) {
    int n = board.size();

    // check if there is a queen in the same column or row
    for (int i = 0; i < n; i++) {
      if (board[i][col] == 'Q') return false;

      if (board[row][i] == 'Q') return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 'Q') return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
      if (board[i][j] == 'Q') return false;
    }

    return true;
  }
};