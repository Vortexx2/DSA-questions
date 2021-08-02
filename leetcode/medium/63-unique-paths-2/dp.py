"""
  @author Vortexx2
  Problem 63 - Unique Paths II

  Runtime - 36 ms
  Memory Usage - 14.4 MB
"""
from typing import List


class Solution:
  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
    rows, cols = len(obstacleGrid), len(obstacleGrid[0])

    if obstacleGrid[rows - 1][cols - 1]:
      return 0

    dp = [[1] * cols for _ in range(rows)] 
    found = False
    for i in range(cols - 1, -1, -1):
      if found or obstacleGrid[rows - 1][i]:
        found = True
        dp[rows - 1][i] = 0

    found = False
    for i in range(rows - 1, -1, -1):
      if found or obstacleGrid[i][cols - 1]:
        found = True
        dp[i][cols - 1] = 0

    for i in range(rows - 2, -1, -1):
      for j in range(cols - 2, -1, -1):
        if obstacleGrid[i][j]:
          dp[i][j] = 0

        else:
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1]

    return dp[0][0]


if __name__ == "__main__":
  sol = Solution()
  print(sol.uniquePathsWithObstacles([[0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0], [0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0], [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1], [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0], [1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0], [
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0], [0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0], [1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0], [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0], [0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0], [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]))
