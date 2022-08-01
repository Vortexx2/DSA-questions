"""
  @author Vortexx2
  Problem 1314 - Matrix Block Sum

  Runtime - 122 ms
  Memory Usage - 15.2 MB
"""
from typing import List


class Solution:
  def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:

    m, n = len(mat), len(mat[0])

    def computePrefixSum() -> List[List[int]]:

      prefixSum = [[0] * (n + 1) for _ in range(m + 1)]

      for i in range(1, m + 1):
        for j in range(1, n + 1):
          prefixSum[i][j] = prefixSum[i - 1][j] + \
              prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1]

      return prefixSum

    prefixSum = computePrefixSum()
    ans = [[0] * n for _ in range(m)] 

    for i in range(m):
      for j in range(n):
        topLeft = (max(0, i - k) + 1, max(0, j - k) + 1)
        bottomRight = (min(m - 1, i + k) + 1, min(n - 1, j + k) + 1)

        ans[i][j] = prefixSum[bottomRight[0]][bottomRight[1]] - prefixSum[topLeft[0] - 1][bottomRight[1]] - prefixSum[bottomRight[0]][topLeft[1] - 1] + prefixSum[topLeft[0] - 1][topLeft[1] - 1]

    return ans
