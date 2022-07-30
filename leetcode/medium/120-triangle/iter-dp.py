"""
  @author Vortexx2
  Problem 120 - Triangle

  Runtime - 102 ms
  Memory Usage - 14.9 MB
"""
from typing import List


class Solution:
  def minimumTotal(self, triangle: List[List[int]]) -> int:
    height = len(triangle)

    if height == 1:
      return triangle[0][0]

    prevRowDP = triangle[height - 1]

    for row in range(height - 2, -1, -1):
      currRowDP = [0] * len(triangle[row])

      for i, num in enumerate(triangle[row]):
        currRowDP[i] = num + min(prevRowDP[i], prevRowDP[i + 1])

      prevRowDP = currRowDP

    return prevRowDP[0]
