"""
  @author Vortexx2
  Problem 714 - Best Time to Buy and Sell Stocks with Txn. Fees

  Runtime - 1327 ms
  Memory Usage - 21.3 MB
"""
from typing import List


class Solution:
  def maxProfit(self, prices: List[int], fee: int) -> int:
    cash, hold = 0, -prices[0]

    for i in range(1, len(prices)):
      cash = max(cash, hold + prices[i] - fee)
      hold = max(hold, cash - prices[i])

    return cash
