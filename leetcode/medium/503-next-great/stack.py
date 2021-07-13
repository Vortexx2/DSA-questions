from typing import List


class Solution:
  def nextGreaterElements(self, nums: List[int]) -> List[int]:
    """
      @author Vortexx2
      Problem 503 - Next Greater Element II
      @approach Using 2 scans and 1 stack. In 1st scan make sure each closable case is closed
      right on the spot. 2nd spot is for the requirement that the arr is circular.

      Runtime - 200 ms
      Memory Usage - 15.7 MB
    """
    st = []
    res = [-1] * len(nums)

    for i, num in enumerate(nums):

      while (len(st) and num > nums[st[-1]]):
        res[st.pop()] = num

      st.append(i)

    for i, num in enumerate(nums):

      if not len(st):
        break

      while (len(st) and num > nums[st[-1]]):
        res[st.pop()] = num

    return res
