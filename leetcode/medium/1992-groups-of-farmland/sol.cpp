/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1992 - Find All Groups of Farmland
 * @date 21-04-2024
 *
 * Runtime - 119 ms
 * Memory Usage - 75.5 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows, cols;
    vector<vector<int>> res;
    pair<int, int> currTopLeft;
    pair<int, int> currBottomRight;

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        res = {};
        rows = land.size(), cols = land[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (land[i][j] == 1) {
                    currTopLeft = {i, j};
                    currBottomRight = {i, j};

                    dfs(i, j, land);

                    res.push_back({currTopLeft.first, currTopLeft.second,
                                   currBottomRight.first,
                                   currBottomRight.second});
                }
            }
        }

        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& land) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || land[i][j] != 1) return;

        land[i][j] = -1;

        currBottomRight = {max(currBottomRight.first, i),
                           max(currBottomRight.second, j)};

        for (auto& d : dirs) {
            dfs(i + d.first, j + d.second, land);
        }
    }
};