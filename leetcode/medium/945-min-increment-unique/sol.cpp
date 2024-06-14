/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 945 -
 * @approach Using a count sort based approach
 * @date 14-06-2024
 *
 * Runtime - 78 ms O(n)
 * Memory Usage - 71.2 MB O(maxElement)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<int> counts(maxElement + 1, 0);

        for (auto& n : nums) counts[n]++;

        int res = 0;
        for (int i = 0; i < counts.size() - 1; i++) {
            if (counts[i] > 0) {
                counts[i + 1] = counts[i + 1] + counts[i] - 1;

                res += counts[i] - 1;
                counts[i] = 1;
            }
        }

        if (counts[counts.size() - 1] > 1) {
            int x = counts[counts.size() - 1];
            res += (x * (x - 1)) / 2;
        }

        return res;
    }
};