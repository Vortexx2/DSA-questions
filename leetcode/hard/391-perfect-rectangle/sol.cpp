/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 391 - Perfect Rectangle
 * @approach Using a count of points appraoch
 * @date 02-01-2023
 *
 * Runtime - 144 ms O(n)
 * Memory Usage - 32 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int n = rectangles.size();

    if (n == 1) return true;

    // maps all points to a respective calculation. If it is a valid rectangle,
    // all interior points should have count 0, bootom left most and top right
    // most point should have value 1, and top left and bottom right should have
    // count -1. If it is different than this, it is not a perfect rectangle.
    map<pair<int, int>, int> pointCounts;

    for (auto& rect : rectangles) {
      pointCounts[{rect[0], rect[1]}]++;
      pointCounts[{rect[2], rect[3]}]++;
      pointCounts[{rect[0], rect[3]}]--;
      pointCounts[{rect[2], rect[1]}]--;
    }

    int numMarks = 0;

    for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
      if (it->second != 0) {
        if (abs(it->second) != 1) return false;

        numMarks++;
      }
    }

    return numMarks == 4;
  }
};