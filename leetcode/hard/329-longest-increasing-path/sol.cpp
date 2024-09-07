/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 329 - Longest Increasing Path in a Matrix
 * 
 * 
 * @approach Using a 2D DP Approach
 * Runtime - 54 ms O(n ^ 2)
 * Memory Usage - 36.57 MB O(n ^ 2)
 * @date 2024-09-07
 */
#include <bits/stdc++.h>

using namespace std;

bool DecreasingComparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
   public:
    const vector<pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> getSortedIndices(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        // we will get all indices sorted descendingly according to values in
        // the matrix

        // this array will store (valueInMatrix, x, y)
        vector<vector<int>> valuesWithIndices;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                valuesWithIndices.push_back({matrix[i][j], i, j});
            }
        }

        sort(valuesWithIndices.begin(), valuesWithIndices.end(),
             DecreasingComparator);

        return valuesWithIndices;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        // -1 in this dp matrix indicates not computed yet
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        auto valuesWithIndices = getSortedIndices(matrix);

        int globalMax = 0;

        for (auto& valueWithIndex : valuesWithIndices) {
            int val = valueWithIndex[0], x = valueWithIndex[1],
                y = valueWithIndex[2];

            int currMax = 0;

            for (auto& changeDir : directions) {
                int dx, dy;
                tie(dx, dy) = changeDir;

                int newX = x + dx, newY = y + dy;

                // out of bounds
                if (newX < 0 || newY < 0 || newX >= rows || newY >= cols)
                    continue;

                if (matrix[newX][newY] <= val) continue;

                currMax = max(currMax, dp[newX][newY]);
            }

            dp[x][y] = currMax + 1;
            globalMax = max(globalMax, dp[x][y]);
        }

        return globalMax;
    }
};