"""
  @author Vortexx2
  Problem 1249 - Minimum Remove to Make Valid Parentheses
  @approach Scanning string twice. Once forward and then backwards.

  Runtime - 432 ms
  Memory Usage - 15.9 MB
"""
class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:

    count = 0
    temp = ""

    for ch in s:

      if ch == '(':
        count += 1

      elif ch == ')':
        if (not count):
          continue

        count -= 1

      temp += ch

    count = 0
    res = ""
    for ch in reversed(temp):

      if ch == ')':
        count += 1

      elif ch == '(':

        if not count:
          continue

        count -= 1

      res = ch + res

    return res
