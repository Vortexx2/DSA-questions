/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 22 - Generate Parentheses
 * @approach Using recursive backtracking
 * @date 20-12-2022
 * 
 * Runtime - 5 ms
 * Memory Usage - 11.6 MB
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> res;
  string path;

  vector<string> generateParenthesis(int n) {
    if (n == 1) return {"()"};

    res = {};
    path = "(";

    helper(n - 1, 1);

    return res;
  }

  void helper(int openingLeft, int toClose) {
    if (!openingLeft && !toClose) {
      res.push_back(path);
      return;
    }

    if (toClose) {
      path.push_back(')');
      helper(openingLeft, toClose - 1);
      path.pop_back();
    }

    if (openingLeft) {
      path.push_back('(');
      helper(openingLeft - 1, toClose + 1);
      path.pop_back();
    }
  }
};