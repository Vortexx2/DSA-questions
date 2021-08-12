"""
  @author Vortexx2
  Problem 39 - Combination Sum

  Runtime - 48 ms
  Memory Usage - 14.5 MB
"""
from typing import List


class Solution:
  def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    candidates = sorted(candidates)
    res = []

    def dfs(target: int, path: List[int], index: int):
      if target == 0:
        res.append(path)
        return

      for i in range(index, len(candidates)):
        if candidates[i] > target:
          return

        dfs(target - candidates[i], path + [candidates[i]], i)

    dfs(target, [], 0)
    return res
