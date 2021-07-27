"""
  @author Vortexx2
  Problem 509

  Runtime - 24 ms
  Memory Usage - 14.3 MB
"""


class Solution:
  def fib(self, n: int) -> int:
    """ Binet's formula """
    root = 5 ** 0.5
    phi = (1 + root) / 2

    return int((phi ** n + 1) / root)
