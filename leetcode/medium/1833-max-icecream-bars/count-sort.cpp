/**
 * @file count-sort.cpp
 * @author Vortexx2
 * @brief Problem 1833 - Maximum Ice Cream Bars
 * @date 06-01-2023
 * 
 * Runtime - 159 ms O(n + m)
 * Memory Usage - 80.6 MB O(m)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    int n = costs.size();

    auto maxElement = *max_element(costs.begin(), costs.end());

    vector<int> arr(maxElement + 1);

    for (int i = 0; i < n; i++) {
      arr[costs[i]]++;
    }

    int res = 0, numToAdd = 0;
    for (int i = 1; i < maxElement + 1; i++) {
      if (i > coins) return res;

      if (arr[i]) {
        numToAdd = min(arr[i], (coins / i));
        coins -= (numToAdd * i);
        res += numToAdd;
      }
    }

    return res;
  }
};