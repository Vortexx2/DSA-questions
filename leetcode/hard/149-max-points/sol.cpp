/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 149 - Max Points on a Line
 * @approach Using arctan2 to easily calculate angles for each line
 * @date 26-12-2022
 * 
 * Runtime - 52 ms O(n^2)
 * Memory Usage - 20.3 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();

    if (n == 1) return 1;

    int maxPts = 2;
    int x1, x2, y1, y2;
    float theta;

    for (int i = 0; i < n - 1; i++) {
      x1 = points[i][0], y1 = points[i][1];

      // maps angle to number of points with given angle
      unordered_map<double, int> dic;

      // we need to start this loop from 0, because only for the 2 extreme
      // points that lie on any line, will all angles be equal to the exam same
      // double number. Otherwise it might be +- pi.
      for (int j = 0; j < n; j++) {
        if (i == j) continue;

        x2 = points[j][0], y2 = points[j][1];

        double theta = atan2(y2 - y1, x2 - x1);

        dic[theta]++;

        maxPts = max(maxPts, dic[theta] + 1);
      }
    }

    return maxPts;
  }
};