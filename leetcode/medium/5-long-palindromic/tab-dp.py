from typing import List


class Solution:
  def longestPalindrome(self, s: str) -> str:
    n = len(s)

    dp: List[List[bool]] = [[True for _ in range(n)] for _ in range(n)]

    maxLen = 1
    res = s[0]

    for size in range(1, n):
      for i in range(n - size):

        if size == 1:

          if s[i] == s[i + size]:

            if size + 1 > maxLen:
              maxLen = size + 1
              res = s[i: i + size + 1]

            dp[i][i + size] = True

          else:
            dp[i][i + size] = False

        else:

          if s[i] == s[i + size] and dp[i + 1][i + size - 1]:

            if size + 1 > maxLen:
              maxLen = size + 1
              res = s[i: i + size + 1]

            dp[i][i + size] = True

          else:
            dp[i][i + size] = False

    return res
