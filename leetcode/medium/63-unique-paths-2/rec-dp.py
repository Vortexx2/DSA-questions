"""
  @author Vortexx2
  Problem 63 - Unique Paths II

  Runtime - 48 ms
  Memory Usage - 15.5 MB
"""
from typing import List


class Solution:
  def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

    if not obstacleGrid:
      return 0

    if obstacleGrid[len(obstacleGrid) - 1][len(obstacleGrid[0]) - 1]:
      return 0

    dic = {}
    return self.helper(obstacleGrid, dic)

  def helper(self, obs: List[List[int]], dic, i: int = 0, j: int = 0):

    if obs[i][j]:
      return 0

    if i == len(obs) - 1 and j == len(obs[0]) - 1:
      return 1

    key = str(i) + "," + str(j)

    if key in dic:
      return dic[key]

    if i == len(obs) - 1:
      dic[key] = self.helper(obs, dic, i, j + 1)

    elif j == len(obs[0]) - 1:
      dic[key] = self.helper(obs, dic, i + 1, j)

    else:
      dic[key] = self.helper(obs, dic, i + 1, j) + \
          self.helper(obs, dic, i, j + 1)

    return dic[key]
