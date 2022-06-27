"""
  @author Vortexx2
  Problem 70 - Climbing Stairs

  Runtime - 43 ms
  Memory Usage - 13.8 MB
"""
class Solution:
  def climbStairs(self, n: int) -> int:

    if (n <= 3):
      return n

    a, b, res = 1, 2, 0

    for _ in range(n - 2):
      res = a + b
      a = b
      b = res

    return res
