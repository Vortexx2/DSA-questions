"""
  @author Vortexx2
  Problem 1249
  @approach Using a stack to keep track of the indices of the open ( parentheses.

  Runtime - 92 ms
  Memory Usage - 16 MB
"""

class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:

    if not s:
      return ""

    s = list(s)
    stack = []

    for i, ch in enumerate(s):

      if ch == '(':
        stack.append(i)

      elif ch == ')':

        if len(stack):
          stack.pop()

        else:
          s[i] = ""

    for el in stack:

      s[el] = ""

    return "".join(s)
