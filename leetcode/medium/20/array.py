"""
  @author Vortexx2
  Problem 20 - Valid Parentheses
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.

  @approach - Iterative approach using an array
"""
class Solution:
  def isValid(self, s: str) -> bool:
    openMap = {
        '}': '{',
        ']': '[',
        ')': '('
    }
    stack = []

    for ch in s:

      if (ch == '{' or ch == '(' or ch == '['):
        stack.append(ch)

      else:

        if (len(stack) == 0):
          return False

        if (stack[-1] == openMap[ch]):
          stack.pop()

        else:
          return False

    return not len(stack)
