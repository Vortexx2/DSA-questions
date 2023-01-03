"""
  @author Vortexx2
  Problem 290 - Word Pattern
  @approach - Reference (https://leetcode.com/problems/word-pattern/solutions/2977027/python-3-2-lines-w-explanation-t-m-98-100/)

  Runtime - 52 ms O(n)
  Memory Usage - 13.8 MB O(n)
"""
from itertools import zip_longest


class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:
    words = s.split()

    return (len(set(pattern)) == len(set(words)) == len(set(zip_longest(pattern, words))))
