/**
 * @file iter.cpp
 * @author Vortexx2
 * @brief Problem 191 - Number of 1 Bits
 * @approach Using bit shifting
 * @date 16-10-2022
 * 
 * Runtime - 4 ms O(n) where n is the number of bits in the number
 * Memory Usage - 5.9 MB O(1)
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    uint32_t b = 0b1;

    int count = 0;

    for (int i = 0; i < 32; i++) {
      if (b & n == 1) count++;

      b = b << 1;
    }

    return count;
  }
};
