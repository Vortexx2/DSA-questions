/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 17 - Letter Combinations of a Phone Number
 * @approach Using backtracking
 * @date 19-12-2022
 * 
 * Runtime - 0 ms
 * Memory Usage - 6.8 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  unordered_map<char, vector<char>> dic = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

  vector<string> res;
  string path;
  int n;

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    n = digits.size();

    res = {};
    path = "";

    helper(digits, 0);

    return res;
  }

  void helper(string& digits, int start) {
    if (start == n) {
      res.push_back(path);
      return;
    }

    for (auto& c : dic[digits[start]]) {
      path.push_back(c);

      helper(digits, start + 1);

      path.pop_back();
    }
  }
};