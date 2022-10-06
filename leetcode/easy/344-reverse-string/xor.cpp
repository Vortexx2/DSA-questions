/**
 * @file xor.cpp
 * @author Vortexx2
 * @brief Problem 344 - Reverse String
 * @approach Using XOR to swap the characters
 * @date 06-10-2022
 * 
 * Runtime - 20 ms O(n)
 * Memory Usage - 23.3 MB O(1)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    int n = s.size();
    int l = 0, r = n - 1;

    while (l < r) {
      s[l] ^= s[r];
      s[r] ^= s[l];
      s[l] ^= s[r];

      l++;
      r--;
    }
  }
};