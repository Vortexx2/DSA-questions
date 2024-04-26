/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 1289 - Minimum Falling Path Sum 2
 * @approach Using a bottom up DP approach
 * @date 26-04-2024
 *
 * Runtime - 92 ms O(n ^ 3)
 * Memory Usage - 18.15 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 1) return grid[0][0];

        vector<int> currDp = grid[n - 1];
        vector<int> nextDp(n, 0);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                // go through every position for j except for j in currDp
                // (previous)
                int minVal = INT_MAX;
                for (int k = 0; k < n; k++) {
                    // skip if same column
                    if (k == j) continue;

                    minVal = min(minVal, currDp[k]);
                }

                nextDp[j] = grid[i][j] + minVal;
            }

            currDp = nextDp;
            nextDp = vector<int>(n, 0);
        }

        int minOnLastIter = INT_MAX;
        for (auto val : currDp) minOnLastIter = min(minOnLastIter, val);

        return minOnLastIter;
    }
};