class Solution:
  def minInsertions(self, s: str) -> int:

    # lefts is the number of lefts needed to balance string, not necessarily
    # rights is the number of rights needed to balance string
    lefts, rights = 0, 0

    for ch in s:

      if ch == "(":
        # for each left open, we need 2 more right closed brackets
        rights += 2

        # this condition signifies that 2 consecutive closes do not exist
        # or "()"
        if (rights % 2 == 1):
          lefts += 1
          rights -= 1

      else:

        # if you have not met any "("
        if not rights:
          lefts += 1
          rights += 1

        else:
          rights -= 1

    return lefts + rights
