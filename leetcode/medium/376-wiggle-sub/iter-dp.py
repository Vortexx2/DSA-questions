"""
  @author Vortexx2
  Problem 376 - Wiggle Subsequence

  Runtime - 309 ms O(n ^ 2)
  Memory Usage - 13.9 MB O(n)
"""
from typing import List


class Solution:
  def wiggleMaxLength(self, nums: List[int]) -> int:

    n = len(nums)

    if (n == 1):
      return 1

    wiggleLengths = [1 for _ in range(n)]
    diffs = [1 for _ in range(n)]
    maxLength = 1

    for i in range(1, n):
      for j in range(i):

        if nums[i] == nums[j]:
          wiggleLengths[i] = 0

        else:
          if j == 0:
            wiggleLengths[i] = 2
            diffs[i] = nums[i] - nums[j]

          else:
            if (nums[i] - nums[j]) * diffs[j] < 0 and (wiggleLengths[i] <= wiggleLengths[j]):
              wiggleLengths[i] = 1 + wiggleLengths[j]
              diffs[i] = nums[i] - nums[j]

      maxLength = max(maxLength, wiggleLengths[i])

    return maxLength
