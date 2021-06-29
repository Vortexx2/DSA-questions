"""
  @author Vortexx2
  Problem 382 - Linked List Random Node
  Given a singly linked list, return a random node's value from the linked list.
  Each node must have the same probability of being chosen.

  Runtime - 88 ms
  Memory Usage - 17.3 MB
"""
import random


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:

  def __init__(self, head: ListNode):
    """
    @param head The linked list's head.
    Note that the head is guaranteed to be not null, so it contains at least one node.
    """
    self.head = head

  def getRandom(self) -> int:
    """
    Returns a random node's value.
    """
    curr = self.head.next
    val = self.head.val
    i = 2

    while (curr is not None):

      if (random.random() < (1 / i)):
        val = curr.val

      curr = curr.next
      i += 1

    return val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
