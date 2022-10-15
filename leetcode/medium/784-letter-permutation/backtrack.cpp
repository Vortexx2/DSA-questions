/**
 * @file rec.cpp
 * @author Vortexx2
 * @brief Problem 784 - Letter Case Permutation
 * @approach Recursive / Backtracking
 * @date 15-10-2022
 * 
 * Runtime - 12 ms O(2^n) - T(n) = 2 * T(n - 1) + d
 * Memory Usage - 10.1 MB O(n) - Recursive stack size
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> res;
    helper(s, 0, res);

    return res;
  }

  void helper(string& s, int start, vector<string>& res) {
    if (start == s.size()) {
      res.push_back(s);
      return;
    }

    // check if current character is alphabetic
    if (isalpha(s[start])) {
      char original = s[start];
      // either
      // we could keep the letter as lowercase
      s[start] = tolower(s[start]);
      helper(s, start + 1, res);
      s[start] = original;

      // or we could uppercase it
      s[start] = toupper(s[start]);
      helper(s, start + 1, res);
      s[start] = original;
    }

    else if (isdigit(s[start])) {
      helper(s, start + 1, res);
    }
  }
};