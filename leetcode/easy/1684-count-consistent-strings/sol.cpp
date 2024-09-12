/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1684 - Count the Number of Consistent Strings
 * 
 * Runtime - 50 ms
 * Memory Usage - 33.97 MB
 * @date 2024-09-12
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> allowedCounter;
        for (auto& c : allowed) allowedCounter[c]++;

        int res = 0;
        for (auto& w : words) {
            bool consistent = true;
            for (auto& c : w) {
                if (!allowedCounter[c]) {
                    consistent = false;
                    break;
                }
            }

            if (consistent) res++;
        }

        return res;
    }
};