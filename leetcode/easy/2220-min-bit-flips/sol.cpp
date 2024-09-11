/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 2220 - Minimum Bit Flips to Convert Number
 * @approach Using XOR
 * 
 * Runtime - 3 ms O(log n)
 * Memory Usage - 7.69 MB O(1)
 * @date 2024-09-11
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int minBitFlips(int start, int goal) {
        int flips = start ^ goal;

        int res = 0;
        while (flips) {
            res += flips % 2;

            flips /= 2;
        }

        return res;
    }
};