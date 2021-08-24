class Complex:
  def __init__(self, real: int, comp: int):
    self.real = real
    self.comp = comp

  def __str__(self):
    return f"{str(self.real)}+{str(self.comp)}i"

  @classmethod
  def strToComplex(cls, num: str) -> complex:
    real = ""
    i = 0
    while num[i] != "+":
      real += num[i]
      i += 1

    i += 1
    comp = ""
    while num[i] != "i":
      comp += num[i]
      i += 1

    real, comp = int(real), int(comp)
    return Complex(real, comp)

  def __mul__(self, other: complex) -> complex:
    real = self.real * other.real - self.comp * other.comp
    comp = other.real * self.comp + self.real * other.comp
    return Complex(real, comp)


class Solution:
  def complexNumberMultiply(self, num1: str, num2: str) -> str:
    a, b = Complex.strToComplex(num1), Complex.strToComplex(num2)
    c = a * b
    return str(c)


if __name__ == '__main__':
  sol = Solution()
  sol.complexNumberMultiply("12+1i", "1+1i")
