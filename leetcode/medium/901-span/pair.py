"""
  @author Vortexx2
  Problem 901 - Online Stock Span
  @approach Using one stack to keep track of most recent largest (price, span). This stack
  will be popped until the top most element is greater than the current price. 

  Runtime - 596 ms
  Memory Usage - 18.8 MB
"""


class StockSpanner:

  def __init__(self):
    self.st = []

  def next(self, price: int) -> int:
    res = 1

    while (len(self.st) and price >= self.st[-1][0]):
      res += self.st[-1][1]
      self.st.pop()

    self.st.append((price, res))
    return res

    # Your StockSpanner object will be instantiated and called as such:
    # obj = StockSpanner()
    # param_1 = obj.next(price)
