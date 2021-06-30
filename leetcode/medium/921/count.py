"""
  @author Vortexx2
  Problem 921 - Minimum Add to Make Parentheses Valid
  @approach Maintaining a balance for the open parentheses

  Runtime - 24 ms
  Memory Usage - 14.4 MB
"""

class Solution:
  def minAddToMakeValid(self, s: str) -> int:

    bal = count = 0

    for ch in s:

      bal += 1 if ch == '(' else -1

      if bal == -1:
        bal = 0
        count += 1

    return bal + count
