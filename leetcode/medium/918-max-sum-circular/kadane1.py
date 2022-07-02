"""
  @author Vortexx2
  Problem 918 - Max Sum Circular Subarray

  Runtime - 598 ms
  Memory Usage - 19.1 MB
"""
from typing import List

from pyparsing import Optional


class Solution:
  def maxSubarraySumCircular(self, nums: List[int]) -> int:

    if len(nums) == 1:
      return nums[0]

    inverted = self.invertedLargest(nums)
    kadane = self.kadaneLargest(nums)

    if inverted is None: return kadane

    return max(inverted, kadane)

  def kadaneLargest(self, nums: List[int]) -> int:
    max_sum, curr_sum = nums[0], nums[0]

    for i in range(1, len(nums)):
      curr_sum = max(curr_sum + nums[i], nums[i])
      max_sum = max(curr_sum, max_sum)

    return max_sum

  def invertedLargest(self, nums: List[int]) -> Optional[int]:

    running_sum, max_sum, curr_sum = nums[0], -nums[0], -nums[0]

    for i in range(1, len(nums)):

      curr_sum = max(curr_sum - nums[i], -nums[i])
      max_sum = max(curr_sum, max_sum)

      running_sum += nums[i]

    if (max_sum + running_sum) == 0:
      return None

    return max_sum + running_sum
