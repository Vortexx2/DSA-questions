"""
  @author Vortexx2
  Problem 509 - Fibonacci Number

  Runtime - 32 ms
  Memory Usage - 14.1 MB
"""
from typing import List


class Solution:
  def fib(self, n: int) -> int:
    dp = [0, 1, 1]

    return self.helper(n, dp)

  def helper(self, n: int, arr: List[int]) -> int:
    if n < len(arr):
      return arr[n]

    arr.append(self.helper(n - 1, arr) + self.helper(n - 2, arr))
    return arr[n]
