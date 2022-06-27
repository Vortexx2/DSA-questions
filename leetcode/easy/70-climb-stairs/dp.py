"""
  @author Vortexx2
  Problem 70 - Climbing Stairs

  Runtime - 32 ms
  Memory Usage - 13.8 MB
"""


class Solution:
  def climbStairs(self, n: int) -> int:

    if n <= 3:
      return n

    self.dp = [0, 1, 2, 3]
    return self.helper(n)

  def helper(self, n: int) -> int:

    if n < len(self.dp):
      return self.dp[n]

    self.dp.append(self.helper(n - 1) + self.helper(n - 2))
    return self.dp[n]
