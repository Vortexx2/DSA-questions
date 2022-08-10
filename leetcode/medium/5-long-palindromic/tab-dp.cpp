/**
 * @file tab-dp.cpp
 * @author Vortexx2
 * @brief Problem 5 - Longest Palindromic Substring
 * @approach Using a tabulation DP approach to build up the solution
 * @date 10-08-2022
 *
 * Runtime - 385 ms O(n ^ 2)
 * Memory Usage - 35.2 MB O(n ^ 2)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();

    // dp maps (i, j) to if substring s[i: j + 1] is a palindrome or not,
    // diagonal is true since s[i: i + 1] is 1 character and is a palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, true));

    // remember the max length and the result string
    int maxLen = 1;
    string res = string(1, s[0]);

    // loop over the string with sizes of the substrings starting from 2
    // actual substring size is `(size + 1)`
    for (int size = 1; size < n; size++) {
      for (int i = 0; i < n - size; i++) {
        // check for 2 character palindromes
        if (size == 1) {
          // for 2 characters, it is a palindrome if first and last character
          // are the same
          if (s[i] == s[i + size]) {
            // if this palindrome exceeds max palindrome
            if (size + 1 > maxLen) {
              maxLen = size + 1;
              res = s.substr(i, size + 1);
            }

            dp[i][i + size] = true;
          }

          else
            dp[i][i + size] = false;
        }

        // check for len >= 3 character palindromes
        else {
          // it is a palindrome if first and last character are the same and the
          // substring in the middle is a palindrome as well
          if (s[i] == s[i + size] && dp[i + 1][i + size - 1]) {
            // if this palindrome exceeds max palindrome
            if (size + 1 > maxLen) {
              maxLen = size + 1;
              res = s.substr(i, size + 1);
            }

            dp[i][i + size] = true;
          }

          else
            dp[i][i + size] = false;
        }
      }
    }

    return res;
  }
};