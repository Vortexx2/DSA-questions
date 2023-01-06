/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 1833 - Maximum Ice Cream Bars
 * @date 06-01-2023
 *
 * Runtime - 278 ms O(nlogn)
 * Memory Usage - 76.5 MB O(1)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    int n = costs.size();
    sort(costs.begin(), costs.end());

    int res = 0;

    for (int i = 0; i < n; i++) {
      if (costs[i] > coins) return res;
      res++;
      coins -= costs[i];
    }
    return res;
  }
};