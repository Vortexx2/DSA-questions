/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 242 - Valid Anagram
 * @date 26-12-2022
 * 
 * Runtime - 14 ms O(n)
 * Memory Usage - 7.4 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> dic;

    for (int i = 0; i < s.size(); i++) dic[s[i]]++;

    for (int i = 0; i < t.size(); i++) {
      if (!dic[t[i]]) return false;

      dic[t[i]]--;

      if (!dic[t[i]]) dic.erase(t[i]);
    }

    return dic.empty();
  }
};