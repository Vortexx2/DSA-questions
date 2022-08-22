"""
  @author Vortexx2
  Problem 300 - Longest Increasing Subsequence

  Runtime - TLE
"""
from typing import List


class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:

    def helper(prev_i, i):
      if i == len(nums):
        return 0

      if memo[prev_i + 1][i] >= 0:
        return memo[prev_i + 1][i]

      add, notAdd = 0, 0
      if prev_i < 0 or nums[i] > nums[prev_i]:
        add = 1 + helper(i, i + 1)

      notAdd = helper(prev_i, i + 1)
      memo[prev_i + 1][i] = max(add, notAdd)
      return memo[prev_i + 1][i]

    N = len(nums)
    memo = [[-1 for _ in range(N)] for _ in range(N)]
    return helper(-1, 0)
