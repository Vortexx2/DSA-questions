/**
 * @file simple-bitmask.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 1371 - Find the Longest Substring Containing Vowels in Even Counts
 * 
 * Runtime - 2327 ms O(n)
 * Memory Usage - 502.3 MB O(n)
 * @date 2024-09-15
 */
#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    return vowels.find(c) != vowels.end();
}

class Solution {
   public:
    int findTheLongestSubstring(string s) {
        // pattern is a bitmask where 1 indicates odd occurrences
        // we flip a bit at the position where we encounter a vowel
        // this will store the position where we first found this pattern
        unordered_map<int, int> patterns = {{0, -1}};
        int mask = 0;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isVowel(c)) {
                mask = mask ^ (1 << (int)(c - 'a'));
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