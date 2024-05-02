/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 2000 - Reverse Prefix of Word
 * @date 02-05-2024
 *
 * Runtime - 0 ms O(n)
 * Memory Usage - 7.78 MB O(n)
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string reversePrefix(string word, char ch) {
        int occurrence = -1;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                occurrence = i;
                break;
            }
        }

        if (occurrence == -1) return word;

        string prefix = word.substr(0, occurrence + 1);
        reverse(prefix.begin(), prefix.end());

        return prefix + word.substr(occurrence + 1);
    }
};