"""
  @author Vortexx2
  Problem 121 - Best Time to Buy And Sell Stock

  Runtime - 1113 ms
  Memory Usage - 25 MB
"""
from typing import List


class Solution:
  def maxProfit(self, prices: List[int]) -> int:

    minPrice, maxProfit = prices[0], 0

    for i in range(1, len(prices)):
      maxProfit = max(maxProfit, prices[i] - minPrice)
      minPrice = min(minPrice, prices[i])

    return maxProfit
