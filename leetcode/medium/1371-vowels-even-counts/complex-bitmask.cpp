/**
 * @file complex-bitmask.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1371 - Find the Longest Substring Containing Vowels in Even Counts
 * @approach Using a bit more complex vowel to mask mapping
 * 
 * Runtime - 2276 ms O(n)
 * Memory Usage - 
 * @date 2024-09-16
 */
#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

class Solution {
   public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelToMask = {
            {'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
        // pattern is a bitmask where 1 indicates odd occurrences
        // we flip a bit at the position where we encounter a vowel
        // this will store the position where we first found this pattern
        unordered_map<int, int> patterns = {{0, -1}};
        int mask = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isVowel(c)) {
                mask = mask ^ vowelToMask[c];
            }

            // this pattern was not found before
            if (patterns.find(mask) == patterns.end()) {
                patterns[mask] = i;
            }

            else {
                int currLength = i - patterns[mask];
                res = max(res, currLength);
            }
        }

        return res;
    }
};