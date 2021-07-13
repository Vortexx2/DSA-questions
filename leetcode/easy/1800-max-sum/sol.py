"""
  @author Vortexx2
  Problem 1800 - Maximum Ascending Subarray Sum

  Runtime - 32 ms
  Memory Usage - 14 MB
"""
from typing import List


class Solution:
  def maxAscendingSum(self, nums: List[int]) -> int:
    maxSum, currSum = 0, 0
    lastEl = 0

    for num in nums:

      if num <= lastEl:
        if currSum > maxSum:
          maxSum = currSum
        currSum = 0

      currSum += num
      lastEl = num

    maxSum = max(maxSum, currSum)

    return maxSum
