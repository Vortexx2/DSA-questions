"""
  @author Vortexx2
  Problem 264 - Ugly Number 2

  Runtime - 171 ms
  Memory Usage - 13.9 MB
"""
class Solution:
  def nthUglyNumber(self, n: int) -> int:

    uglys = [0] * (n + 1)
    uglys[1] = 1

    i2, i3, i5 = 1, 1, 1
    next_multiple_of_2, next_multiple_of_3, next_multiple_of_5 = 2, 3, 5

    curr_ugly = 1

    for i in range(2, n + 1):

      curr_ugly = min(next_multiple_of_2,
                      next_multiple_of_3, next_multiple_of_5)

      uglys[i] = curr_ugly

      if curr_ugly == next_multiple_of_2:
        i2 += 1
        next_multiple_of_2 = uglys[i2] * 2

      if curr_ugly == next_multiple_of_3:
        i3 += 1
        next_multiple_of_3 = uglys[i3] * 3

      if curr_ugly == next_multiple_of_5:
        i5 += 1
        next_multiple_of_5 = uglys[i5] * 5

    return curr_ugly
