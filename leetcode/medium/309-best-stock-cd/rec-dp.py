"""
  @author Vortexx2
  Problem 309 - Best Time to Buy and Sell Stock with Cooldown

  Runtime - 88 ms
  Memory Usage - 17.8 MB
"""
from typing import List


class Solution:
  def maxProfit(self, prices: List[int]) -> int:

    dp = {}  # maps (i, boughtStock) to maxProfit for that decision

    def dfs(i: int, boughtStock: bool) -> int:

      if i >= len(prices):
        return 0

      if (i, boughtStock) in dp:
        return dp[(i, boughtStock)]

      if boughtStock:
        sell = dfs(i + 2, False) + prices[i]
        cd = dfs(i + 1, True)
        dp[(i, boughtStock)] = max(sell, cd)

      else:
        buy = dfs(i + 1, True) - prices[i]
        cd = dfs(i + 1, False)
        dp[(i, boughtStock)] = max(buy, cd)

      return dp[(i, boughtStock)]

    return dfs(0, False)
