"""
  @author Vortexx2
  Problem 746 - Minimum Cost in Climbing Stairs

  Runtime - 93 ms
  Memory Usage - 14.4 MB
"""
from typing import List


class Solution:
  def minCostClimbingStairs(self, cost: List[int]) -> int:

    if len(cost) <= 1:
      return 0

    self.dp = [0, 0]
    return self.minCost(cost, len(cost))

  def minCost(self, cost: List[int], current: int) -> int:

    if current < len(self.dp):
      return self.dp[current]

    self.dp.append(min(self.minCost(cost, current - 2) +
                   cost[current - 2], self.minCost(cost, current - 1) + cost[current - 1]))

    return self.dp[current]
