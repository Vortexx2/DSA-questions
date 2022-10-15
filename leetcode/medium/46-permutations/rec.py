"""
  @author Vortexx2
  Problem 46 - Permutations

  Runtime - 73 ms O(n !)
  Memory Usage - 14 MB O(n)
"""
from typing import List


class Solution:
  def permute(self, nums: List[int]) -> List[List[int]]:
    return self.helper(nums, 0)

  def helper(self, nums: List[int], start: int) -> List[List[int]]:

    if start == len(nums) - 1:
      return [[nums[-1]]]

    res = self.helper(nums, start + 1)
    newRes = []

    for path in res:

      for i in range(len(path) + 1):
        newPath = path[:i] + [nums[start]] + path[i:]
        newRes.append(newPath)

    return newRes
