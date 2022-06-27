/**
 * @file dp.cpp
 * @author Vortexx2
 * @brief Problem 746 - Minimum Cost Climbing Stairs
 * @date 27-06-2022
 *
 * Runtime - 6 ms
 * Memory Usage - 14.1 MB
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dp = {0, 0};
  int minCostClimbingStairs(vector<int>& cost) {
    if (cost.size() <= 1) return 0;

    return minCost(cost, cost.size());
  }

  int minCost(vector<int>& cost, int current) {
    if (current < dp.size()) return dp[current];

    dp.push_back(min(minCost(cost, current - 2) + cost[current - 2],
                     minCost(cost, current - 1) + cost[current - 1]));

    return dp[current];
  }
};