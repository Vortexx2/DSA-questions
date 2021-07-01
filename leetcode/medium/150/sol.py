"""
  @author Vortexx2
  Problem 150 - Evaluate RPN
  Using stack
"""
from typing import List
from collections import deque


def is_numeric(s: str):
  for char in s:
    if char.isnumeric():
      return True

  return False


def operate(a: int, b: int, token: str) -> int:

  if (token == "+"):
    return a + b

  if (token == "*"):
    return a * b

  if (token == "-"):
    return a - b

  return int(a / b)


class Solution:
  def evalRPN(self, tokens: List[str]) -> int:
    de = deque([])
    for token in tokens:

      if (is_numeric(token)):
        de.append(int(token))

      else:
        a, b = de.pop(), de.pop()
        res = operate(b, a, token)
        de.append(res)

    return de.pop()


if __name__ == '__main__':
  sol = Solution()
  print(sol.evalRPN(["10", "6", "9", "3", "+",
        "-11", "*", "/", "*", "17", "+", "5", "+"]))
