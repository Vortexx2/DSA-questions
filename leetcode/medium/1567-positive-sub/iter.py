"""
  @author Vortexx2
  Problem 1567 - Maximum Length of Subarray with Positive Product

  Runtime - 600 ms
  Memory Usage - 28.1 MB
"""
from typing import List


class Solution:
  def getMaxLen(self, nums: List[int]) -> int:

    currNeg, currPos, maxLen = 0, 0, 0

    for num in nums:
      
      # num == 0
      if not num:
        currPos, currNeg = 0, 0

      elif num < 0:

        if currNeg:
          temp = currNeg
          currNeg = currPos + 1
          currPos = temp + 1

        else:
          currNeg = currPos + 1
          currPos = 0

      else:

        if currNeg:
          currNeg += 1
        
        currPos += 1
      
      maxLen = max(maxLen, currPos)

    return maxLen


