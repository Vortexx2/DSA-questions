/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1219 - Path with Maximum Gold
 * @date 17-05-2024
 *
 * Runtime - 128 ms O(25 * m * n)
 * Memory Usage - 9.08 MB O(max(m, n))
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int m, n;

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        int maxVal = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) maxVal = max(maxVal, rec(grid, i, j));
            }
        }

        return maxVal;
    }

    int rec(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) return 0;

        int currGold = grid[i][j];
        grid[i][j] = 0;

        int maxVal = INT_MIN;
        for (auto& d : dirs) {
            int newRow = i + d.first, newCol = j + d.second;

            int recMax = currGold + rec(grid, newRow, newCol);
            maxVal = max(maxVal, recMax);
        }

        grid[i][j] = currGold;
        return maxVal;
    }
};