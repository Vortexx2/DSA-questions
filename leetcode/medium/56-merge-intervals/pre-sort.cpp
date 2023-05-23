/**
 * @file pre-sort.cpp
 * @author Vortexx2
 * @brief Problem 56 - Merge Intervals
 * @approach Using presorting
 * @date 23-05-2023
 * 
 * Runtime - 206 ms O(n * log n)
 * Memory Usage - 47.1 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto comp = [](vector<int> a, vector<int> b) { return a[0] < b[0]; };

    // sort intervals by the start of the interval
    sort(intervals.begin(), intervals.end(), comp);

    vector<vector<int>> res;

    int n = intervals.size();
    // initialise to very first interval
    vector<int> currInterval = intervals[0];

    for (int i = 1; i < n; i++) {
      // no overlap
      if (intervals[i][0] > currInterval[1]) {
        res.push_back(currInterval);

        currInterval = intervals[i];
      }

      // there is overlap
      else {
        currInterval = {currInterval[0], max(currInterval[1], intervals[i][1])};
      }
    }

    res.push_back(currInterval);
    return res;
  }
};