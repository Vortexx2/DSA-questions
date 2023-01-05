/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 452 - Minimum Arrows to Burst Balloons
 * @date 05-01-2023
 *
 * Runtime - 938 ms O(n * logn)
 * Memory Usage - 89.7 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

bool sortByStarting(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // sort points array by starting times
    sort(points.begin(), points.end(), sortByStarting);

    int i = 0, numArrows = 0;

    while (i < points.size()) {
      int minEndingPoint = points[i][1];
      i++;

      // if xstart of new point is still lesser than curr min ending point
      while (i < points.size() && points[i][0] <= minEndingPoint) {
        minEndingPoint = min(minEndingPoint, points[i][1]);
        i++;
      }

      numArrows++;
    }

    return numArrows;
  }
};