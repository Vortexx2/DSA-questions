"""
  @author Vortexx2
  Problem 300 - Longest Increasing Subsequence

  Runtime - 3128 ms O(n ^ 2)
  Memory Usage - 14.2 MB O(n)
"""
from typing import List


class Solution:
  def lengthOfLIS(self, nums: List[int]) -> int:
    n = len(nums)

    maxLen = 1
    increasingSub = [1 for _ in range(n)]

    for i in range(1, n):
      for j in range(i):
        if (nums[i] > nums[j] and increasingSub[i] <= increasingSub[j]):
          increasingSub[i] = 1 + increasingSub[j]

      maxLen = max(maxLen, increasingSub[i])

    return maxLen