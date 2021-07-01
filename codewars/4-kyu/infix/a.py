from collections import deque


def to_postfix(infix: str):
  """Convert infix to postfix"""

  de = deque([])
  val = ""
  prec = {
      '+': 1,
      '-': 1,
      '*': 2,
      '/': 2,
      '^': 3,
      '(': -1
  }

  for ch in infix:

    if ch.isnumeric():
      val += ch

    elif ch == "(":
      de.append(ch)

    elif ch == ")":
      while de[-1] != "(":
        val += de.pop()

      de.pop()

    else:

      while (len(de) != 0 and prec[ch] <= prec[de[-1]]):
        val += de.pop()

      de.append(ch)

  while len(de) != 0:
    val += de.pop()

  return val


if __name__ == '__main__':
  print(to_postfix("1^2^3"))
