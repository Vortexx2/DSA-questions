/**
 * @file greedy.cpp
 * @author Vortexx2
 * @brief Problem 441 - Arranging Coins
 * @approach Greedy simple approach
 * @date 30-09-2022
 * 
 * Runtime - 16 ms O(n)
 * Memory Usage - 5.8 MB O(1)
 */
#include <iostream>

using namespace std;

class Solution {
 public:
  int arrangeCoins(int n) {
    int i = 1;
    int numRows = 0;

    while (n > 0) {
      numRows++;
      i++;
      n = n - i;
    }

    return numRows;
  }
};