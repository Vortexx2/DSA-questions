"""
  Problem 109 - Sorted LL to BST

  Runtime - 136 ms
  Memory Usage - 17.8 MB
"""
from typing import Optional


# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
    if not head:
      return None

    if not head.next:
      return TreeNode(head.val)

    p, mid = self.middleNode(head)

    newNode = TreeNode(mid.val)
    if p:
      p.next = None
      newNode.left = self.sortedListToBST(head)

    newNode.right = self.sortedListToBST(mid.next)

    return newNode

  def middleNode(self, head: Optional[ListNode]):
    if not head:
      return None

    slow, fast = head, head
    prev = None

    while fast.next is not None and fast.next.next is not None:
      prev = slow
      slow = slow.next
      fast = fast.next.next

    return (prev, slow)
