/**
 * @file window.cpp
 * @author Vortexx2
 * @brief Problem 3 - Longest Substring Without Repeating Characters
 * @date 08-10-2022
 * 
 * Runtime - 57 ms O(n)
 * Memory Usage - 13.5 MB O(n)
 */
#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();

    if (n < 2) return n;

    // maps character to if it has been encountered in current substring or not
    map<char, bool> encountered = {};
    int l = 0, r = 0;
    int maxLength = 0;

    while (r < n) {
      while (l <= r && encountered.find(s[r]) != encountered.end()) {
        encountered.erase(s[l++]);
      }

      maxLength = max(maxLength, r - l + 1);

      encountered[s[r]] = true;
      r++;
    }

    return maxLength;
  }
};