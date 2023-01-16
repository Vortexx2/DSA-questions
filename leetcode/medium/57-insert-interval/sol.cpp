/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 57 - Insert Interval
 * @date 16-01-2023
 * 
 * Runtime - 4 ms O(n)
 * Memory Usage - 17.1 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // `i` will indicate the position to place the new interval
    int i = 0, n = intervals.size();
    int newLeft = newInterval[0], newRight = newInterval[1];

    if (n == 0) return {{newLeft, newRight}};

    bool inserted = false;
    vector<vector<int>> res;

    while (i < n) {
      auto interval = intervals[i];

      // new interval lies completely on left
      if (newRight < interval[0]) {
        if (!inserted) {
          res.push_back({newLeft, newRight});
          inserted = true;
        }
        res.push_back(interval);
        i++;
      }

      // new interval lies completely on the right
      else if (newLeft > interval[1]) {
        res.push_back(interval);
        i++;
      }

      // interval is overlapping
      else {
        while (i < n && (newLeft <= interval[1] && newRight >= interval[0])) {
          newLeft = min(newLeft, interval[0]);
          newRight = max(newRight, interval[1]);

          i++;
          if (i == n) {
            res.push_back({newLeft, newRight});
            inserted = true;
            break;
          }

          interval = intervals[i];
        }
      }
    }

    if (!inserted) res.push_back({newLeft, newRight});

    return res;
  }
};