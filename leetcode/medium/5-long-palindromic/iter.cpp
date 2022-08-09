/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 5 - Longest Palindromic Substring
 * @approach - Iterating through the string to figure out the longest palindrome
 * when the current character is the middle of the palindrome. (Refer to this
 * video: https://www.youtube.com/watch?v=XYQecbcd6_c)
 * @date 09-08-2022
 *
 * Runtime - 25 ms
 * Memory Usage - 19 MB
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string res = "";
    int resLen = 0;

    // for each character in the string, we find out the largest palindrome
    // possible as that character as the middle of the palindrome
    for (int i = 0; i < s.size(); i++) {
      // odd length palindromes
      int left = i, right = i;

      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > resLen) {
          res = s.substr(left, right - left + 1);
          resLen = right - left + 1;
        }

        left--;
        right++;
      }

      // even length palindromes
      left = i, right = i + 1;

      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > resLen) {
          res = s.substr(left, right - left + 1);
          resLen = right - left + 1;
        }
        left--;
        right++;
      }
    }

    return res;
  }
};