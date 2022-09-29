"""
  @author Vortexx2
  Problem 72 - Edit Distance

  Runtime - 209 ms
  Memory Usage - 17.7 MB
"""


class Solution:
  def minDistance(self, word1: str, word2: str) -> int:

    self.m, self.n = len(word1), len(word2)

    self.dp = [[0 for _ in range(self.n + 1)] for _ in range(self.m + 1)]
    self.fillInitialValues()

    for i in range(self.m - 1, -1, -1):
      for j in range(self.n - 1, -1, -1):

        if word1[i] == word2[j]:
          self.dp[i][j] = self.dp[i + 1][j + 1]

        else:
          self.dp[i][j] = min(1 + self.dp[i + 1][j], 1 +
                              self.dp[i][j + 1], 1 + self.dp[i + 1][j + 1])

    return self.dp[0][0]

  def fillInitialValues(self) -> None:

    for i in range(self.m + 1):
      self.dp[i][self.n] = self.m - i

    for i in range(self.n + 1):
      self.dp[self.m][i] = self.n - i

    print(self.dp)


sol = Solution()
s1 = "horse"
s2 = "ros"
print(sol.minDistance(s1, s2))
