"""
  @author Vortexx2
  Problem 931 - Minimum Falling Path

  Runtime - 315 ms
  Memory Usage - 22.8 MB
"""
from typing import List


class Solution:
  def minFallingPathSum(self, matrix: List[List[int]]) -> int:

    dp = {}

    def helper(row: int, col: int) -> int:

      if col == -1 or col == len(matrix):
        return float('inf')

      if row == len(matrix) - 1:
        return matrix[row][col]

      if (row, col) in dp:
        return dp[(row, col)]

      dp[(row, col)] = matrix[row][col] + min(helper(row + 1, col - 1),
                                              helper(row + 1, col),
                                              helper(row + 1, col + 1))

      return dp[(row, col)]

    minVal = helper(0, 0)
    for i in range(1, len(matrix)):
      minVal = min(minVal, helper(0, i))

    return minVal
