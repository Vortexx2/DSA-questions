"""
  @author Vortexx2
  Problem 376 - Wiggle Subsequence

  Runtime - 51 ms O(n)
  Memory Usage - 13.9 MB O(n)
"""
from typing import List


class Solution:

  def wiggleMaxLength(self, nums: List[int]) -> int:

    n = len(nums)
    ups = [1] * n
    downs = [1] * n

    for i in range(1, n):

      if nums[i] > nums[i - 1]:
        ups[i] = downs[i - 1] + 1
        downs[i] = downs[i - 1]

      elif nums[i] < nums[i - 1]:
        ups[i] = ups[i - 1]
        downs[i] = ups[i - 1] + 1

      else:
        ups[i] = ups[i - 1]
        downs[i] = downs[i - 1]

    return max(ups[n - 1], downs[n - 1])
