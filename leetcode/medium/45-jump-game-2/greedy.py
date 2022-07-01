"""
  @author Vortexx2
  Problem 45 - Jump Game 2

  Runtime - 197 ms
  Memory Usage - 15 MB
"""
from typing import List


class Solution:
  def jump(self, nums: List[int]) -> int:

    n = len(nums)

    if (n <= 2):
      return n - 1

    interval = (0, 0)
    jumps = 0

    while (True):

      if (interval[1] >= n - 1):
        return jumps
      
      jumps += 1
      can_reach = -1

      for i in range(interval[0], interval[1] + 1):
        can_reach = max(can_reach, i + nums[i])

      interval = (interval[1] + 1, can_reach)
