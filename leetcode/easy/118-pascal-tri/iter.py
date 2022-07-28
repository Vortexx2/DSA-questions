"""
  @author Vortexx2
  Problem 118 - Pascal's Triangle

  Runtime - 19 ms
  Memory Usage - 13.9 MB
"""
from typing import List


class Solution:
  def generate(self, numRows: int) -> List[List[int]]:
    res = [[]] * numRows

    for rowNum in range(numRows):
      row = [1] * (rowNum + 1)

      for i in range(1, rowNum):
        row[i] = res[rowNum - 1][i - 1] + res[rowNum - 1][i]

      res[rowNum] = row

    return res
