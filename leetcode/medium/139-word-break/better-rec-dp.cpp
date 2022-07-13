/**
 * @file better-rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 139 - Word Break
 * @date 13-07-2022
 * 
 * Runtime - 28 ms O(n^3)
 * Memory Usage - 13.7 MB O(n)
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  map<string, bool> dict;
  map<int, bool> dp;
  bool wordBreak(string s, vector<string>& wordDict) {
    populateMap(wordDict);

    return recursive(s, 0);
  }

  // populates dictionary with all words in the `wordDict`, so as to have access
  // in constant time to all dictionary words
  void populateMap(vector<string>& dictArr) {
    dict.insert({"", true});
    for (string& s : dictArr) {
      dict.insert({s, true});
    }
  }

  // checks if given word is a provided word
  bool isValidWord(string word) { return dict.find(word) != dict.end(); }

  bool recursive(string& s, int pos) {
    if (pos >= s.size()) return true;

    if (dp.find(pos) != dp.end()) return dp[pos];

    for (int i = pos; i < s.size(); i++) {
      if (isValidWord(s.substr(pos, i - pos + 1)) && recursive(s, i + 1)) {
        dp[pos] = true;
        return true;
      }

      else {
        dp[pos] = false;
      }
    }

    return false;
  }
};