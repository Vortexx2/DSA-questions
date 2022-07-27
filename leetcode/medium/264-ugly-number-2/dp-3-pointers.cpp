/**
 * @file dp-3-pointers.cpp
 * @author Vortexx2
 * @brief Problem 264 - Ugly Number 2
 * @approach - Using 3 pointers for each factor on a DP array filled with all of
 * the ugly numbers. We know, that if we multiply any of the ugly numbers with
 * any of the factors, we get another ugly number. Therefore, if we keep track
 * fo the last number that we multiplied with a given factor, we can figure out
 * the next ugly number.
 * @date 27-07-2022
 *
 * Runtime - 12 ms O(n)
 * Memory Usage - 7.5 MB O(n)
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    // index in the array of uglys to multiply with the respective factor
    int i2 = 1, i3 = 1, i5 = 1;
    int currUgly = 1;

    // store all of the ugly numbers
    vector<int> uglys(n + 1);
    uglys[1] = 1;

    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 2; i <= n; i++) {
      // next ugly number will be the minimum of the multiples
      currUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));

      uglys[i] = currUgly;

      // below if statements need to be run for each individual case separately,
      // if next multiples for 2 separate factors are the same, both of them
      // need to be changed so that no ugly numbers are repeats
      if (currUgly == nextMultipleOf2) {
        i2++;
        nextMultipleOf2 = uglys[i2] * 2;
      }

      if (currUgly == nextMultipleOf3) {
        i3++;
        nextMultipleOf3 = uglys[i3] * 3;
      }

      if (currUgly == nextMultipleOf5) {
        i5++;
        nextMultipleOf5 = uglys[i5] * 5;
      }
    }

    return currUgly;
  }
};