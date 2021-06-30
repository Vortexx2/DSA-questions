"""
  @author Vortexx2
  Problem 921 - Minimum Add to Make Parentheses Valid
  @approach Deque (stack) based approach 

  Runtime - 28 ms
  Memory Usage - 14.4 MB 
"""
from collections import deque


class Solution:
  def minAddToMakeValid(self, s: str) -> int:

    st = deque([])
    count = 0

    for ch in s:

      if ch == '(':
        st.append(ch)

      else:

        if len(st) == 0:
          count += 1

        else:
          st.pop()

    count += len(st)

    return count
