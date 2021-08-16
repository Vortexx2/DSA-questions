"""
  @author Vortexx2
  Problem 96 - Unique BST

  Runtime - 28 ms
  Memory Usage - 14 MB
"""


class Solution:
  def numTrees(self, n: int) -> int:
    dp = [1] * (n + 1)

    for i in range(2, n + 1):
      dp[i] = 0
      for j in range(i):
        dp[i] += dp[j] * dp[i - j - 1]

    return dp[n]
