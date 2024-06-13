/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 75 - Sort Colors
 * @approach Count sort
 * @date 13-06-2024
 *
 * Runtime - 5 ms O(n)
 * Memory Usage - O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(3, 0);

        for (auto& n : nums) counts[n]++;

        int numsPointer = 0;
        for (int i = 0; i < 3; i++) {
            while (counts[i]) {
                nums[numsPointer++] = i;
                counts[i]--;
            }
        }
    }
};