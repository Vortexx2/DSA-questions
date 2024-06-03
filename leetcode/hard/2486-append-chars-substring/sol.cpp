/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2486 - Append Characters to String to Make Subsequence
 * @date 03-06-2024
 *
 * Runtime - 16 ms O(n)
 * Memory Usage - 11.91 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int appendCharacters(string s, string t) {
        // t has to be a subsequence of s

        int sPointer = 0, tPointer = 0;
        while (sPointer < s.size() && tPointer < t.size()) {
            if (s[sPointer] == t[tPointer]) tPointer++;
            sPointer++;
        }

        if (tPointer == t.size()) return 0;

        return t.size() - tPointer;
    }
};