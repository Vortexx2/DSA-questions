"""
  @author Vortexx2
  Problem 496 - Next Greatest Number I

  Runtime - 76 ms
  Memory Usage - 14.4 MB
"""
from typing import List


class Solution:
  def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
    dic = {}
    
    for i, num in enumerate(nums2):
      dic[num] = i

    for i, num in enumerate(nums1):
      nums1[i] = -1

      for j in range(dic[num] + 1, len(nums2)):

        if nums2[j] > num:
          nums1[i] = nums2[j]
          break

    return nums1


