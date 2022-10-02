"""
  @author Vortexx2
  Problem 377 - Combination Sum 4
  @approach Using a bottom up tabulation DP approach

  Runtime - 32 ms O(nums * target)
  Memory Usage - 13.9 MB O(target)
"""
from typing import List


class Solution:
  def combinationSum4(self, nums: List[int], target: int) -> int:

    if not target:
      return 1

    n = len(nums)
    dp = [0] * (target + 1)
    dp[0] = 1

    for subAmount in range(1, target + 1):

      ways = 0

      for num in nums:
        if num == subAmount:
          ways += 1

        if num < subAmount:
          ways += dp[subAmount - num]

      dp[subAmount] = ways

    return dp[target]
