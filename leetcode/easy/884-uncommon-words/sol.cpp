/**
 * @file sol.cpp
 * @author Vortexx2 (you@domain.com)
 * @brief Problem 884 - Uncommon Words From 2 Sentences
 * 
 * Runtime - 0 ms O(m + n)
 * Memory Usage - 8.79 MB O(m + n)
 * @date 2024-09-17
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;

        string currWord = "";
        for (auto &c : s1) {
            if (c != ' ')
                currWord += c;

            else {
                words[currWord]++;
                currWord = "";
            }
        }
        words[currWord]++;

        currWord = "";
        for (auto &c : s2) {
            if (c != ' ')
                currWord += c;

            else {
                words[currWord]++;
                currWord = "";
            }
        }
        words[currWord]++;

        vector<string> res;
        for (auto it = words.begin(); it != words.end(); it++) {
            if (it->second == 1) res.push_back(it->first);
        }

        return res;
    }
};