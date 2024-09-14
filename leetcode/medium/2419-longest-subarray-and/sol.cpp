/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 2419 - Longest Subarray with Maximum Bitwise AND
 * @approach Using a logic simplifier -
 * If x > y, then x & y <= y
 * Therefore, the largest number will be the longest subarray if all elements are distinct
 * Therefore, we need to find longest subarray of largest number
 * 
 * Runtime - 95 ms O(n)
 * Memory Usage - 84.74 MB O(1)
 * @date 2024-09-14
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        // we simply need to find longest subarray of largest number
        int largestNum = nums[0];
        int longestSeq = 1;

        int currSeq = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == largestNum && nums[i - 1] == largestNum) {
                currSeq++;
                longestSeq = max(currSeq, longestSeq);
            }

            else {
                if (nums[i] > largestNum) {
                    largestNum = nums[i];
                    longestSeq = 1;
                }
                currSeq = 1;
            }
        }

        longestSeq = max(currSeq, longestSeq);

        return longestSeq;
    }
};