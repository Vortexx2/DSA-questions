/**
 * @file brute-force.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 28 - First Occurrence in a String
 * @approach - Brute Force
 * 
 * Runtime - 0 ms O(m * n)
 * @date 2024-09-21
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int l = 0, r = 0;

        int targetSize = haystack.size(), patternSize = needle.size();

        for (int i = 0; i < targetSize; i++) {
            int r = i;
            int needleIndex = 0;

            while (r < targetSize && needleIndex < patternSize) {
                if (haystack[r] != needle[needleIndex]) break;

                r++;
                needleIndex++;
            }

            if (needleIndex == patternSize) return i;
        }

        return -1;

    }
};