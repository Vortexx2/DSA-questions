from collections import deque


def lexSmallestString(input1: int, input2: str) -> str:
  """
    Let there be 3 robots: A, B and C.
    A has a string `input2` of length `input1`.
    A can append letters to B only through the front of the string.
    B can append letters to C only through the end of the string.
    Find the lexicographically smallest string C can have

    Ex: "dad" ---- ans ----> "add"
    Ex: "cba" ---- ans ----> "abc"
  """

  length = input1

  if not input1:
    return ""

  prevSmallest = length - 1
  dic = {
      prevSmallest: False
  }

  for i in range(length - 2, -1, -1):
    if input2[i] < input2[prevSmallest]:
      dic[i] = False
      prevSmallest = i

    else:
      dic[i] = True

  b, ans = deque(), ""

  for i, char in enumerate(input2):
    b.append(i)

    if dic[i]:
      continue

    while b and not dic[b[-1]]:
      ans += input2[b.pop()]

  while b:
    ans += input2[b.pop()]
  return ans


if __name__ == "__main__":

  inp = "cba"
  print(lexSmallestString(len(inp), inp))
