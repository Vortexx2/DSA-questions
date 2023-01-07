/**
 * @file sol.cpp
 * @author Vortexx2
 * @brief Problem 134 - Gas Stations
 * @approach Greedy
 * @date 08-01-2023
 * 
 * Runtime - 77 ms O(n)
 * Memory Usage - 70.5 MB O(n)
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int gasSum = 0, costSum = 0;
    for (int i = 0; i < n; i++) {
      gasSum += gas[i];
      costSum += cost[i];
    }

    if (gasSum < costSum) return -1;

    vector<int> diffs(n);

    for (int i = 0; i < n; i++) {
      diffs[i] = gas[i] - cost[i];
    }

    int start = 0, total = 0;
    while (start < n) {
      if (diffs[start] < 0) {
        start++;
        continue;
      }

      total = diffs[start];
      int i = (start + 1) % n;
      while (i != start && total >= 0) {
        total += diffs[i];
        i = (i + 1) % n;
      }

      if (i == start)
        return start;

      else
        start = i;
    }

    return n - 1;
  }
};