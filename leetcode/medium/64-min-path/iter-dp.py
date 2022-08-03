"""
  @author Vortexx2
  Problem 64 - Minimum Path Sum
  @approach Using a row by row iterative DP approach

  Runtime - 171 ms
  Memory Usage - 14.7 MB
"""
from typing import List


class Solution:
  def minPathSum(self, grid: List[List[int]]) -> int:

    rows, cols = len(grid), len(grid[0])

    def firstRow() -> List[int]:
      row = [0] * cols
      row[0] = grid[0][0]

      for i in range(1, cols):
        row[i] = row[i - 1] + grid[0][i]

      return row

    row = firstRow()

    for i in range(1, rows):
      for j in range(0, cols):

        if j:
          row[j] = min(row[j - 1], row[j])

        row[j] += grid[i][j]

    return row[cols - 1]
