class Solution:
  def isUgly(self, n: int) -> bool:
    factors = [2, 3, 5]

    if (n <= 0):
      return False

    def recursive(n: int) -> bool:

      if n == 1:
        return True

      for factor in factors:
        if n % factor == 0:
          if recursive(n / factor):
            return True

      return False

    return recursive(n)
