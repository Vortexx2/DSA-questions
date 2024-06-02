/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 3110 - Score of a String
 * @date 02-06-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.83 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 1; i < s.size(); i++) {
            score += abs(s[i] - s[i - 1]);
        }

        return score;
    }
};