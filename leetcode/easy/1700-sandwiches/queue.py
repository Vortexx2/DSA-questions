"""
  @author Vortexx2
  Problem 1700 - Number of students unable to eat lunch

  Runtime - 16 ms
  Memory Usage - 14.3 MB
"""
from typing import List
from collections import deque


class Solution:
  def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
    """
      @approach Go through students once and strike off all sandwiches that can be eaten in the first go. If student can't eat sandwich, push index to queue. Then -> for the length of queue, try to strike of sandwiches. If after one iteration over length of queue length does not decrease, we have reached the end.
    """
    dq = deque([])
    i, j = 0, 0

    while i < len(students):
      if j == len(sandwiches):
        return 0

      if students[i] == sandwiches[j]:
        j += 1

      else:
        dq.appendleft(i)

      i += 1

    count = len(dq)
    while count:

      for i in range(count):
        if students[dq[-1]] == sandwiches[j]:
          dq.pop()
          j += 1

        else:
          dq.appendleft(dq.pop())

      if count == len(dq):
        return count

      count = len(dq)

    return 0


if __name__ == "__main__":
  sol = Solution()
  print(sol.countStudents([1, 1, 0, 0], [0, 1, 0, 1]))
