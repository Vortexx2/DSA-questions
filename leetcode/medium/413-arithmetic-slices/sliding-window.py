"""
  @author Vortexx2
  Problem 413 - Arithmetic Slices

  Runtime - 57 ms
  Memory Usage - 14.1 MB
"""
from typing import List


class Solution:
  def numberOfArithmeticSlices(self, nums: List[int]) -> int:

    n = len(nums)

    if n <= 2:
      return 0

    ans, currPossible = 0, 0
    windowStart, windowEnd = 0, 2
    firstDiff, secondDiff = 0, nums[1] - nums[0]

    while windowEnd < n:

      firstDiff = secondDiff
      secondDiff = nums[windowEnd] - nums[windowEnd - 1]

      if secondDiff == firstDiff:
        currPossible = self.numOfPossibleSubarrays(windowEnd - windowStart + 1)
        windowEnd += 1

      else:
        windowStart = windowEnd - 1
        windowEnd += 1
        ans += currPossible
        currPossible = 0

    ans += currPossible
    return ans

  def numOfPossibleSubarrays(self, length: int) -> int:
    return int(((length - 1) * (length - 2)) / 2)
