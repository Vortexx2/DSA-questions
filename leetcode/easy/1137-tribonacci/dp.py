"""
  @author Vortexx2
  Problem 1137 - Nth Tribonacci Number

  Runtime - 29 ms
  Memory Usage - 13.8 MB
"""


class Solution:
  def tribonacci(self, n: int) -> int:
    self.seq = [0, 1, 1]

    if n <= 2:
      return self.seq[n]

    return self.helper(n)

  def helper(self, n: int) -> int:

    if n < len(self.seq):
      return self.seq[n]

    self.seq.append(self.helper(n - 1) +
                    self.helper(n - 2) + self.helper(n - 3))

    return self.seq[n]
