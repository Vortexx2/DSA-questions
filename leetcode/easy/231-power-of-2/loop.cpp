/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 231 - Power of Two
 * @approach Using a loop
 * @date 16-10-2022
 * 
 * Runtime - 3 ms O(log(n))
 * Memory Usage - 6 MB O(1)
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    while (n != 1) {
      if (n % 2) return false;

      n /= 2;
    }

    return true;
  }
};