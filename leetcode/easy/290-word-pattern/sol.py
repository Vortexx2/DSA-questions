"""
  @author Vortexx2
  Problem 290 - Word Pattern

  Runtime - 52 ms O(n)
  Memory Usage - 14 MB O(n)
"""
class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:

    words = s.split(" ")

    if len(pattern) != len(words):
      return False

    wordToChar, charToWord = {}, {}

    for char, word in zip(pattern, words):

      if char not in charToWord:

        # means, that we have encountered word mapped to some different char before
        if word in wordToChar:
          return False

        charToWord[char] = word
        wordToChar[word] = char

      # means that character was encountered before but word wasn't
      if (char in charToWord) and (word not in wordToChar):
        return False

      if charToWord[char] != word or wordToChar[word] != char:
        return False

    return True
