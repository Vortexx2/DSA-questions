/**
 * @file bsearch.cpp
 * @author Vortexx2
 * @brief Problem 278 - First Bad Version
 * @approach Using a binary search approach since array is already sorted
 * @date 04-10-2022
 * 
 * Runtime - 0 ms O(logn)
 * Memory Usage - 5.9 MB 3O(1)
 */
#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    if (isBadVersion(1)) return 1;

    int low = 1, high = n, mid = (low + high + 1) / 2;

    bool curr = isBadVersion(mid);

    while (high - low > 1) {
      if (curr)
        high = mid;

      else
        low = mid;

      mid = (low + high + 1) / 2;
      curr = isBadVersion(mid);
    }

    return mid;
  }
};