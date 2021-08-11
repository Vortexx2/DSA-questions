"""
  @author Vortexx2
  Problem 77 - Combinations
  @approach Recursive + Backtracking Sol

  Runtime - 68 ms
  Memory Usage - 15.8 MB
"""
from typing import List


class Solution:
  def combine(self, n: int, k: int) -> List[List[int]]:
    path, res = [], []
    for i in range(1, n - k + 2):
      self.helper(n, k - 1, i, path, res)

    return res

  def helper(self, n: int, k: int, curr: int, path: List[int], res: List[List[int]]) -> None:
    path.append(curr)

    if (k == 0):
      res.append(path.copy())
      path.pop()
      return

    for i in range(curr + 1, n - k + 2):
      self.helper(n, k - 1, i, path, res)

    path.pop()
