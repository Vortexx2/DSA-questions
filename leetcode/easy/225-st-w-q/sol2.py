"""
  @author Vortexx2
  Problem 225 Stacks with Two Queues
  @approach Using 2 queues to implement a stack. Preserving the order of the stack by reversing the queue each time on push. Therefore, pop and top can be done with simple pop() and negative indexing.

  Runtime - 32 ms
  Memory Usage - 14 MB
"""
from collections import deque


class MyStack:

  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.a = deque([])
    self.b = deque([])

  def push(self, x: int) -> None:
    """
    Push element x onto stack.
    """

    if self.a:
      self.a.append(x)
      while self.a:
        self.b.append(self.a.popleft())

    else:
      self.b.append(x)
      while self.b:
        self.a.append(self.b.popleft())


  def pop(self) -> int:
    """
    Removes the element on top of the stack and returns that element.
    """
    ans = 0

    if not len(self.a):
      ans = self.b.pop()

    else:
      ans = self.a.pop()

    return ans

  def top(self) -> int:
    """
    Get the top element.
    """
    ans = 0

    if self.a:
      ans = self.a[-1]

    else:
      ans = self.b[-1]

    return ans

  def empty(self) -> bool:
    """
    Returns whether the stack is empty.
    """

    return not (self.a or self.b)


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()


if __name__ == "__main__":
  st = MyStack()
  st.push(1)
  st.push(2)
  print(st.b)