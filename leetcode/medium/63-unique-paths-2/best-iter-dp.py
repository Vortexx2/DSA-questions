"""
  @author Vortexx2
  Problem 63 - Unique Paths 2

  Runtime - 81 ms
  Memory Usage - 13.9 MB
"""
from typing import List


class Solution:
  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

    rows, cols = len(obstacleGrid), len(obstacleGrid[0])

    if obstacleGrid[0][0] or obstacleGrid[rows - 1][cols - 1]:
      return 0

    row = [0] * cols
    row[0] = 1

    for i in range(rows):
      for j in range(cols):

        if obstacleGrid[i][j]:
          row[j] = 0
          continue

        if j:
          row[j] += row[j - 1]

    return row[cols - 1]
