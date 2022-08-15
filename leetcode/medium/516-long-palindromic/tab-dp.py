"""
  @author Vortexx2
  Problem 516 - Longest Palindromic Subsequence

  Runtime - 5180 ms O(n ^ 2)
  Memory Usage - 31.4 MB O(n ^ 2)
"""
from typing import List


class Solution:
  def longestPalindromeSubseq(self, s: str) -> int:

    n = len(s)
    dp: List[List[int]] = [[1 for _ in range(n)] for _ in range(n)]

    maxLen = 1

    for length in range(1, n):
      for i in range(n - length):

        if s[i] == s[i + length]:
          if length == 1:
            dp[i][i + length] = 2

          else:
            dp[i][i + length] = 2 + dp[i + 1][i + length - 1]

        else:
          dp[i][i + length] = max(dp[i][i + length - 1], dp[i + 1][i + length])

        maxLen = max(maxLen, dp[i][i + length])

    return maxLen
