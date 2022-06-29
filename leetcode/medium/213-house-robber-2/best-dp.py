"""
  @author Vortexx2
  Problem 213 - House Robber II
  @approach Iterative DP with least memory usage O(1)
  
  Runtime - 59 ms
  Memory Usage - 13.9 MB
"""
from typing import List


class Solution:
  def rob(self, nums: List[int]) -> int:
    n = len(nums)

    if n <= 3:
      return max(nums)

    return max(self.helper(nums, 0, n-1), self.helper(nums, 1, n))

  def helper(self, nums: List[int], start: int, end: int) -> int:

    a, b = nums[start], max(nums[start], nums[start + 1])
    res = 0

    for i in range(start + 2, end):
      res = max(a + nums[i], b)
      a = b
      b = res

    return res
