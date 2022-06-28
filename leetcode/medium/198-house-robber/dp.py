"""
  @author Vortexx2
  Problem 198

  Runtime - 45 ms
  Memory Usage - 13.9 MB
"""
from typing import List


class Solution:
  def rob(self, nums: List[int]) -> int:

    if len(nums) == 1:
      return nums[0]

    self.dp = [-1] * len(nums)
    return max(self.helper(nums, 0), self.helper(nums, 1))

  def helper(self, nums: List[int], current: int) -> int:
    if current >= len(nums):
      return 0

    if self.dp[current] != -1:
      return self.dp[current]

    self.dp[current] = max(self.helper(nums, current + 2),
                           self.helper(nums, current + 3)) + nums[current]

    return self.dp[current]
