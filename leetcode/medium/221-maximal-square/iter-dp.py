"""
  @user Vortexx2
  Problem 221 - Maximal Square

  Runtime - 586 ms
  Memory Usage - 16.4 MB
"""
from typing import List


class Solution:
  def maximalSquare(self, matrix: List[List[str]]) -> int:

    m, n = len(matrix), len(matrix[0])

    self.maxSide = 0

    """
      Returns the bottom most row for the DP that is required
    """
    def bottomMostRow() -> List[int]:
      res: List[int] = [1] * n

      for i, num in enumerate(matrix[m - 1]):

        if num == "0":
          res[i] = 0

        else:
          self.maxSide = 1
          res[i] = 1

      return res

    # prevRow is the DP that maps the maximal square taking that position as the top left part of the square
    prevRow = bottomMostRow()

    for i in range(m - 2, -1, -1):
      currRow = [1] * n

      for j in range(n - 1, -1, -1):

        # if character is 0, maximal square possible is 0
        if matrix[i][j] == "0":
          currRow[j] = 0

        # if character is 1
        else:

          # if it's not the last position of the column
          if j != n - 1:
            currRow[j] = 1 + min(currRow[j + 1], prevRow[j], prevRow[j + 1])
            self.maxSide = max(self.maxSide, currRow[j])

          # if it's the last position in the column, and character is 1
          else:
            currRow[j] = 1
            self.maxSide = max(self.maxSide, 1)

      prevRow = currRow

    return self.maxSide * self.maxSide
