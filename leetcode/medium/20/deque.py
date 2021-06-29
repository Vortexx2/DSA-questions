"""
  @author Vortexx2
  Problem 20 - Valid Parentheses
  @approach Iterative solution using deque
"""
from collections import deque


class Solution:
  def isValid(self, s: str) -> bool:
    openMap = {
        '}': '{',
        ']': '[',
        ')': '('
    }

    de = deque([])

    for ch in s:

      if ch == '{' or ch == '[' or ch == '(':
        de.append(ch)

      else:

        if not len(de):
          return False

        if de[-1] == openMap[ch]:
          de.pop()

        else:
          return False

    return not len(de)
