"""
  @author Vortexx2
  Problem 139 - Word Break

  Runtime - 54 ms
  Memory Usage - 14.2 MB
"""
from typing import List


class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:

    self.dict = {}

    self.populateMap(wordDict)
    dp = {}

    def recursive(pos: int) -> bool:

      if pos >= len(s):
        return True

      if pos in dp:
        return dp[pos]

      for i in range(pos, len(s)):

        if (s[pos: i + 1] in self.dict and recursive(i + 1)):
          dp[pos] = True
          return True

        dp[pos] = False

      return False

    return recursive(0)

  def populateMap(self, wordDict: List[str]) -> None:
    self.dict[""] = True

    for word in wordDict:
      self.dict[word] = True
