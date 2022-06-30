"""
  @author Vortexx2
  Problem 55 - Jump Game

  Runtime - 495 ms
  Memory Usage - 15.3 MB
"""
from typing import List


class Solution:
  def canJump(self, nums: List[int]) -> bool:

    n = len(nums)
    if n == 1: return True

    goal = n - 1

    for i in range(n - 2, -1, -1):
      if (i + nums[i] >= goal):
        goal = i

    return not goal

