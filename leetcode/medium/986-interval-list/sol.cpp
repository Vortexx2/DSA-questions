/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 986 - Interval List Intersections
 * @approach Using 2 pointers
 * @date 27-10-2022
 * 
 * Runtime - 63 ms O(m + n)
 * Memory Usage - 18.7 MB O(1)
 */
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    firstList.push_back({INT_MAX, INT_MAX});
    secondList.push_back({INT_MAX, INT_MAX});

    vector<vector<int>> res;
    int a = 0, b = 0;

    while (a < firstList.size() && b < secondList.size()) {
      int a1 = firstList[a][0], a2 = firstList[a][1];
      int b1 = secondList[b][0], b2 = secondList[b][1];

      // check if current intervals overlap
      if (a2 >= b1 && a1 <= b2) {
        int start = max(a1, b1), end = min(a2, b2);

        res.push_back({start, end});
      }

      if (a2 > b2)
        b++;
      else
        a++;
    }

    res.pop_back();
    return res;
  }
};