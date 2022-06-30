"""
  @author Vortexx2
  Problem 740 - Delete and Earn

  Runtime - 145 ms
  Memory Usage - 16.1 MB
"""
from typing import List
from collections import Counter


class Solution:
  def deleteAndEarn(self, nums: List[int]) -> int:

    self.counter = Counter(nums)
    unique_vals = sorted(list(self.counter))

    n = len(unique_vals)

    a = self.findValue(unique_vals[0])

    if n == 1:
      return a

    b = self.findSecond(unique_vals[0], unique_vals[1])
    res = b

    for i in range(2, n):
      if unique_vals[i] - unique_vals[i - 1] == 1:
        res = max(a + self.findValue(unique_vals[i]), b)

      else:
        res = b + self.findValue(unique_vals[i])
      
      a = b
      b = res

    return res


  def findValue(self, num: int) -> int:
    return self.counter[num] * num

  def findSecond(self, first_elem: int, sec_elem: int) -> int:

    if (sec_elem - first_elem) == 1:
      return max(self.findValue(sec_elem), self.findValue(first_elem))

    else:
      return self.findValue(sec_elem) + self.findValue(first_elem)

