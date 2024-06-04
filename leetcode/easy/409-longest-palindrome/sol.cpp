/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 409 - Longest Palindrome
 * @date 04-06-2024
 *
 * Runtime - 2 ms O(n)
 * Memory Usage - 9.12 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestPalindrome(string s) {
        unordered_map<char, int> countOfChars;

        for (int i = 0; i < s.size(); i++) {
            countOfChars[s[i]]++;
        }

        bool anyOdd = false;
        int res = 0;
        for (auto it = countOfChars.begin(); it != countOfChars.end(); it++) {
            // it is odd
            if (it->second % 2) anyOdd = true;

            res += floor(it->second / 2) * 2;
        }

        if (anyOdd) res++;
        return res;
    }
};