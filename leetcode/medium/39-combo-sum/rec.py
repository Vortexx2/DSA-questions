"""
  @author Vortexx2
  Problem 39 - Combination Sum

  Runtime - 260 ms
  Memory Usage - 14.4 MB
"""
from typing import List


class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    path, res = [], []
    for i in range(len(candidates)):
      self.helper(candidates, target, i, path, res)

    return res

  def helper(self, cand: List[int], target: int, start: int, path: List[int], res: List[List[int]]) -> None:

    if target < 0:
      return

    path.append(cand[start])
    if target == cand[start]:
      res.append(path.copy())

    else:
      for i in range(start, len(cand)):
        self.helper(cand, target - cand[start], i, path, res)

    path.pop()
