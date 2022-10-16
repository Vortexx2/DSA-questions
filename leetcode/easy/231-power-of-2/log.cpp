/**
 * @file log.cpp
 * @author Vortexx2
 * @brief Problem 231 - Power Of Two
 * @approach Using the properties of log
 * @date 16-10-2022
 * 
 * Runtime - 0 ms O(1)
 * Memory Usage - 5.9 MB O(1)
 */
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    double log = log2(n);
    return ceil(log) == floor(log);
  }
};