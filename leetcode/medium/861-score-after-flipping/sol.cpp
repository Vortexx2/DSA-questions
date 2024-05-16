/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 861 - Score After Flipping Matrix
 * @date 17-05-2024
 *
 * Runtime - 0 ms O(m * n)
 * Memory Usage - 10.28 MB O(1)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int m, n;
    void flipRow(vector<vector<int>>& grid, int row) {
        for (int col = 0; col < n; col++) grid[row][col] = !grid[row][col];
    }

    void flipCol(vector<vector<int>>& grid, int col) {
        for (int row = 0; row < m; row++) grid[row][col] = !grid[row][col];
    }

    int colSum(vector<vector<int>>& grid, int col, bool flip) {
        int sum = 0;
        for (int row = 0; row < m; row++) {
            if (flip)
                sum += !grid[row][col];

            else
                sum += grid[row][col];
        }

        return sum;
    }

    int matrixSum(vector<vector<int>>& grid) {
        int sum = 0;
        for (int matrixRow = 0; matrixRow < m; matrixRow++) {
            int rowNum = 0;
            for (int matrixCol = n - 1; matrixCol >= 0; matrixCol--) {
                rowNum +=
                    grid[matrixRow][matrixCol] * pow(2, (n - 1) - matrixCol);
            }

            sum += rowNum;
        }

        return sum;
    }

    int matrixScore(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int maxMatrixScore = 0;

        // go through each row and flip the entire row if the first bit is 0
        // O(m * n)
        for (int matrixRow = 0; matrixRow < m; matrixRow++) {
            if (grid[matrixRow][0] == 0) flipRow(grid, matrixRow);
        }

        // go through each column and you can flip it or not
        // O(m * n)
        for (int matrixCol = 1; matrixCol < n; matrixCol++) {
            int flippedSum = colSum(grid, matrixCol, true),
                notFlippedSum = colSum(grid, matrixCol, false);

            if (notFlippedSum > flippedSum) continue;

            flipCol(grid, matrixCol);
        }

        return matrixSum(grid);
    }
};