"""
  @author Vortexx2
  Problem 496 - Next Greatest Element I

  Runtime - 60 ms
  Memory Usage - 14.6 MB
"""
from typing import List


class Solution:
  def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
    """
      Using a stack to be able to assign all next greatest elements in the first iteration of
      `nums2`, so as to be able to index it later using `dic`.
    """
    st = []
    dic = {}
    res = [-1] * len(nums1)

    for num in nums2:

      while (len(st) and (num > st[-1])):
        dic[st.pop()] = num

      st.append(num)

    for i, num in enumerate(nums1):
      if num in dic:
        res[i] = dic[num]

    return res
