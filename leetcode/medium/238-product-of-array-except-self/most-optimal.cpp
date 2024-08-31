/**
 * @file most-optimal.cpp
 * @author Vortexx2
 * @brief Problem 238 - Product of Array Except Self
 * 
 * Runtime - 15 ms O(n)
 * Memory Usage - 38.87 MB O(1)
 * @date 2024-08-31
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res = nums;
        int totalProduct = 1;
        int encounteredZeros = 0;

        for (auto& num : nums) {
            if (num) totalProduct *= num;
            if (!num) encounteredZeros++;
        }

        for (int i = 0; i < res.size(); i++) {
            if (nums[i]) {
                if (encounteredZeros)
                    res[i] = 0;
                else
                    res[i] = totalProduct / nums[i];
            } else {
                if (encounteredZeros > 1)
                    res[i] = 0;
                else
                    res[i] = totalProduct;
            }
        }

        return res;
    }
};