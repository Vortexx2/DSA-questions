"""
  @author Vortexx2
  Problem 152 - Max Product Subarray

  Runtime - 80 ms
  Memory Usage - 13.9 MB
"""
from typing import List


class Solution:
  def maxProduct(self, nums: List[int]) -> int:

    n = len(nums)

    if n == 1:
      return nums[0]

    minCurr = maxCurr = maxProd = nums[0]

    for i in range(1, n):

      minTemp = minCurr * nums[i]
      maxTemp = maxCurr * nums[i]

      minCurr = min(minTemp, maxTemp, nums[i])
      maxCurr = max(maxTemp, minTemp, nums[i])

      maxProd = max(maxProd, maxCurr)

    return maxProd
