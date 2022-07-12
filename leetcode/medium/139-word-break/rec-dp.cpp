/**
 * @file rec-dp.cpp
 * @author Vortexx2
 * @brief Problem 139 - Word Break
 * @approach Recursive DP approach similar to a state machine. It is like the
 * state machine technique used for buying and selling stock, where we buy or
 * sell at each stage.
 * @date 12-07-2022
 *
 * Runtime - 390 ms
 * Memory Usage - 57.4 MB
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  map<string, bool> dict;  // dict for words to be accessed in constant time
  map<pair<int, string>, bool>
      dp;  // dp maps (i, currWord) to is word break possible
  bool wordBreak(string s, vector<string>& wordDict) {
    populateMap(wordDict);

    return dfs(s, "", 0);
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
  bool isValidWord(string& word) { return dict.find(word) != dict.end(); }

  bool dfs(string& s, string currWord, int i) {
    // base case
    if (i >= s.size()) {
      return isValidWord(currWord);
    }

    currWord += s[i];

    // dp existence check
    if (dp.find({i, currWord}) != dp.end()) return dp[{i, currWord}];

    if (isValidWord(currWord)) {
      // buy
      bool a = dfs(s, currWord, i + 1);

      // sell
      bool b = dfs(s, "", i + 1);

      dp[{i, currWord}] = a || b;
      return a || b;
    }

    // if currWord is not valid, we'll need to include the current character
    // always i.e. no option to sell
    else {
      dp[{i, currWord}] = dfs(s, currWord, i + 1);
      return dp[{i, currWord}];
    }
  }
};