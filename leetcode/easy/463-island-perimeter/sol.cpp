/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem
 * @date 20-04-2024
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows, cols;

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    recPerimeter(i, j, grid, perimeter);
                    break;
                }
            }
        }

        return perimeter;
    }

    int recPerimeter(int i, int j, vector<vector<int>>& grid,
                     int& currPerimeter) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || !grid[i][j]) return 0;

        if (grid[i][j] == -1) return 1;

        grid[i][j] = -1;

        for (auto& d : dirs) {
            int isLand =
                recPerimeter(i + d.first, j + d.second, grid, currPerimeter);
            if (!isLand) currPerimeter++;
        }

        return 1;
    }
};