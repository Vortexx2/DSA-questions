"""
  @author Vortexx2
  Problem 62 - Unique Paths

  Runtime - 24 ms
  Memory Usage - 14.3 MB
"""
from typing import List, Dict


class Solution:
  def uniquePaths(self, m: int, n: int, dp={}) -> int:

    if not m or not n:
      return 0

    if m == 1 or n == 1:
      return 1

    key = str(m) + ',' + str(n)
    if key in dp:
      return dp[key]

    dp[key] = self.uniquePaths(m - 1, n, dp) + self.uniquePaths(m, n - 1, dp)
    return dp[key]
