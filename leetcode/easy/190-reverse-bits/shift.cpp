/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 190 - Reverse Bits
 * @approach Using shift operators and AND operation to figure out last bit.
 * @date 17-10-2022
 * 
 * Runtime - 0 ms O(n) where n is the number of bits in the input
 * Memory Usage - 5.9 MB O(1) extra space
 */
#include <iostream>

using namespace std;

void bin(uint32_t n) {
  long i;
  cout << "0";
  for (i = 1 << 30; i > 0; i = i / 2) {
    if ((n & i) != 0) {
      cout << "1";
    } else {
      cout << "0";
    }
  }

  cout << endl;
}

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0b0;
    uint32_t anded;

    for (int i = 0; i < 32; i++) {
      ans = ans << 1;
      anded = n & 0b1;

      ans += anded;
      n = n >> 1;
    }

    return ans;
  }
};