/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem
 * @date 10-06-2024
 *
 * Runtime - 5 ms O(n log n)
 * Memory Usage - 10.29 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int heightChecker(vector<int>& heights) {
        vector<int> heightsCopy = heights;

        sort(heightsCopy.begin(), heightsCopy.end());

        int n = heights.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != heightsCopy[i]) res++;
        }

        return res;
    }
};