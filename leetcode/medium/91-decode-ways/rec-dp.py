"""
  @author Vortexx2
  Problem 91 - Decode Ways

  Runtime - 52 ms
  Memory Usage - 14.1
"""
class Solution:
  def numDecodings(self, s: str) -> int:
    dp = {len(s): 1}

    def dfs(i: int) -> int:

      if i in dp:
        return dp[i]

      if s[i] == "0":
        return 0

      res = dfs(i + 1)
      if (i + 1 < len(s) and (s[i] == "1" or (s[i] == "2" and s[i+1] in "0123456"))):
        res += dfs(i + 2)

      dp[i] = res
      return res

    return dfs(0)
