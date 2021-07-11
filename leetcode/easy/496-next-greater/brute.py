"""
  @author Vortexx2
  Problem 496 - Next Greatest Number I

  Runtime - 168 ms
  Memory Usage - 14.4 MB
"""
from typing import List


class Solution:
  def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

    for i, num in enumerate(nums1):
      found = False
      nums1[i] = -1
      for j in nums2:

        if j == num:
          found = True

        if (j > num and found):
          nums1[i] = j
          break


    return nums1
