"""
  @author Vortexx2
  Problem 509

  Runtime - 28 ms
  Memory Usage - 14.2 MB
"""
class Solution:
  def fib(self, n: int) -> int:
    n1, n2 = 0, 1

    if n == 0:
      return n1
    if n == 1:
      return n2

    for _ in range(n - 1):
      n3 = n1 + n2
      n1 = n2
      n2 = n3

    return n3
