class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

# Question :
# You are given two non-empty linked lists representing two non-negative integers.
# The digits are stored in reverse order, and each of their nodes contains a single digit.
# Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.


class Solution:
  def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    prevHead = ListNode()
    prev = prevHead

    carry = 0

    while l1 or l2 or carry:

      sum = l1.val if l1 else 0
      sum += l2.val if l2 else 0
      sum += carry

      newNode = ListNode(sum % 10)
      prev.next = newNode
      prev = prev.next

      carry = sum // 10

      l1 = l1.next if l1 else l1
      l2 = l2.next if l2 else l2

    return prevHead.next
