"""
  @author Vortexx2
  Problem 96 - Unique Binary Search Trees

  Runtime - 24 ms
  Memory Usage - 14.2 MB
"""
class Solution:
  def numTrees(self, n: int) -> int:
    dp = {}

    def helper(n: int) -> int:
      if n <= 1:
        return 1

      if n in dp:
        return dp[n]

      res = 0
      for i in range(0, n):
        left = helper(i)
        right = helper(n - i - 1)
        res += left * right

      dp[n] = res
      return res

    return helper(n)
