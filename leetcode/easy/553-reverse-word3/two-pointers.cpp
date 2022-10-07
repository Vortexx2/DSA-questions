/**
 * @file two-pointers.cpp
 * @author Vortexx2
 * @brief Problem 553 - Reverse Words in a String 3
 * @approach Using 2 pointers, by reversing each word iteratively
 * @date 07-10-2022
 * 
 * Runtime - 26 ms O(n ^ 2)
 * Memory Usage - 13.2 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int n = s.size();

    if (n == 1) return s;

    int l = 0, r = 0;

    string res = "";

    while (r < n) {
      while (r < n && s[r] != ' ') r++;

      string reversedWord = "";
      int i = r - 1;
      while (i >= l) {
        reversedWord += s[i];
        i--;
      }

      res += reversedWord;
      if (s[r] == ' ') res += " ";
      r++;
      l = r;
    }

    return res;
  }
};