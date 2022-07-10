"""
  @author Vortexx2
  Problem 122 - Best Time to Buy and Sell Stock II

  Runtime - 101 ms
  Memory Usage - 15.2 MB
"""
from typing import List


class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    currMin, maxProfit = prices[0], 0

    for i in range(1, len(prices)):
      if prices[i] > currMin:
        maxProfit += (prices[i] - currMin)

      currMin = prices[i]

    return maxProfit

