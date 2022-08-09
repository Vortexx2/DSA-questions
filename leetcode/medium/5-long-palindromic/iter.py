"""
  @author Vortexx2
  Problem 5 - Longest Palindromic Substring

  Runtime - 1594 ms
  Memory Usage - 13.8 MB
"""
class Solution:
  def longestPalindrome(self, s: str) -> str:

    res = ""
    resLen = 0

    for i in range(len(s)):

      # odd length palindromes
      left, right = i, i

      while left >= 0 and right < len(s) and s[left] == s[right]:

        if right - left + 1 > resLen:
          res = s[left: right + 1]
          resLen = right - left + 1

        left -= 1
        right += 1

      # even length palindromes
      left, right = i, i + 1

      while left >= 0 and right < len(s) and s[left] == s[right]:

        if right - left + 1 > resLen:
          res = s[left: right + 1]
          resLen = right - left + 1

        left -= 1
        right += 1

    return res
