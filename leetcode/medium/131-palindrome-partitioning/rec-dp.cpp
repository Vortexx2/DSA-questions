/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 131 - Palindrome Partitioning
 * @date 22-01-2023
 * 
 * Runtime - 132 ms O(n * 2 ^ n)
 * Memory Usage - 75.8 MB O(n ^ 2)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int n;
  vector<vector<bool>> dp;
  vector<vector<string>> res;

  string str;

  void fillPalindromes(string &s) {
    for (int size = 1; size < n; size++) {
      for (int i = 0; i < n - size; i++) {
        // if first and last element of substring are equal, it might be a
        // palindrome
        if (s[i] == s[i + size])
          dp[i][i + size] = dp[i + 1][i + size - 1];

        else
          dp[i][i + size] = false;
      }
    }
  }

  bool isPali(int start, int end) { return dp[start][end]; }

  void rec(int pos, vector<string> &path) {
    if (pos == str.size()) {
      res.push_back(path);
      return;
    }

    for (int i = pos; i < str.size(); i++) {
      if (isPali(pos, i)) {
        path.push_back(str.substr(pos, i - pos + 1));
        rec(i + 1, path);
        path.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    n = s.size();
    dp.resize(n, vector<bool>(n, true));

    str = s;

    fillPalindromes(s);

    vector<string> path;
    rec(0, path);

    return res;
  }
};