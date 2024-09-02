/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 2022 - Convert 1D Array into 2D Array
 * 
 * Runtime - 78 ms O(n)
 * Memory Usage - 87.92 MB O(1) [Extra memory]
 * @date 2024-09-02
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {};
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = original[i * n + j];
            }
        }
        return res;
    }
};