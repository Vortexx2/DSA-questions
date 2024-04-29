/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2997 - Minimum Number of Operations to Make Array XOR Equal to
 * K
 * @date 30-04-2024
 *
 * Runtime - 111 ms O(n)
 * Memory Usage - 91.8 MB O(len(k))
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        int arrXor = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            arrXor ^= nums[i];
        }

        string arrXorStr = bitset<20>(arrXor).to_string();
        string kStr = bitset<20>(k).to_string();

        int res = 0;
        for (int i = 0; i < arrXorStr.size(); i++) {
            if (kStr[i] != arrXorStr[i]) res++;
        }

        return res;
    }
};