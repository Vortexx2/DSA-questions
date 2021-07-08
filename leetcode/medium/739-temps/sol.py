"""
  @author Vortexx2
  Problem 739 - Daily Temperatures
  @approach Using only the `res` array to keep track of greater temps.

  Runtime - 1332 ms
  Memory Usage - 26.1 MB
"""
from typing import List


class Solution:
  def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
    res = [0] * len(temperatures)

    for i in range(len(temperatures) - 1, -1, -1):
      j = i + 1

      while (j < len(temperatures) and (temperatures[i] >= temperatures[j])):

        if res[j] > 0:
          j += res[j]
        else:
          j = len(temperatures)

      if j < len(temperatures):
        res[i] = j - i

    return res
