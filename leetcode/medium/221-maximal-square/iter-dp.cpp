/**
 * @file iter-dp.cpp
 * @author Vortexx2
 * @brief Problem 221 - Maximal Square
 * @approach Tabulation DP approach with the least memory possible
 * @date 07-08-2022
 *
 * Runtime - 101 ms O(m * n)
 * Memory Usage - 18 MB O(n)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSide = 0;
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> prevRow = bottomRow(matrix);

    for (int i = m - 2; i >= 0; i--) {
      vector<int> currRow(n, 1);
      for (int j = n - 1; j >= 0; j--) {
        if (matrix[i][j] == '0')
          currRow[j] = 0;

        else {
          // if it is not the last column and char is 1
          if (j != n - 1)
            currRow[j] =
                1 + min(currRow[j + 1], min(prevRow[j], prevRow[j + 1]));

          // if it is the last column and char is 1
          else
            currRow[j] = 1;

          maxSide = max(maxSide, currRow[j]);
        }
      }

      prevRow = currRow;
    }

    return maxSide * maxSide;
  }

  vector<int> bottomRow(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> res(cols);

    for (int i = 0; i < cols; i++) {
      if (matrix[rows - 1][i] == '0')
        res[i] = 0;

      else {
        maxSide = 1;
        res[i] = 1;
      }
    }

    return res;
  }
};

int main() {
  Solution sol = Solution();
  vector<vector<char>> a = {{'1', '0'}, {'0', '0'}};

  cout << sol.maximalSquare(a) << endl;
}