from typing import Optional


class Node:
  """ Structure of constituent node. Height of node with no children is considered to be 1 """

  def __init__(self, x):
    self.data = x
    self.left = None
    self.right = None
    self.height = 1


class Solution:
  def insertToAVL(self, root: Optional[Node], key: int):
    if not root:
      return Node(key)

    if key < root.data:
      root.left = self.insertToAVL(root.left, key)

    elif key > root.data:
      root.right = self.insertToAVL(root.right, key)

    # return root in case of duplicate key
    else:
      return root

    # update height of current node
    root.height = 1 + max(self.height(root.left), self.height(root.right))

    # get balance factor of current node
    balanceFactor = self.balanceFactor(root)

    # left heavy case, root is guaranteed to have a left child
    # perform right rotation with respect to root
    if (balanceFactor > 1 and root.left.data > key):
      return self.rightRotate(root)

    # right heavy case
    # perform left rotation with respect to root
    if (balanceFactor < -1 and root.right.data < key):
      return self.leftRotate(root)

    # left heavy case (LR)
    # perform left rotation with respect to root.left
    # then right rotation with respect to root
    if (balanceFactor > 1 and root.left.data < key):
      root.left = self.leftRotate(root.left)
      return self.rightRotate(root)

    # right heavy case (RL)
    # perform right rotation with respect to root.right
    # then left rotation with respect to root
    if (balanceFactor < -1 and root.right.data > key):
      root.right = self.rightRotate(root.right)
      return self.leftRotate(root)

    # no balance factor issue with root node
    return root

  def height(self, node: Optional[Node]) -> int:
    """ Utility function to return the height of the node. Returns 0 if node is NULL."""
    if not node:
      return 0

    return node.height

  def balanceFactor(self, node: Optional[Node]) -> int:
    """ Utility function to return the balance factor of the node. Returns 0 if node is NULL """
    if not node:
      return 0

    return self.height(node.left) - self.height(node.right)

  def rightRotate(self, node: Optional[Node]) -> Node:
    # node is guaranteed to have a left node
    left, leftR = node.left, node.left.right

    left.right = node
    node.left = leftR

    # Updating heights
    node.height = 1 + max(self.height(node.left), self.height(node.right))
    left.height = 1 + max(self.height(left.left), self.height(left.right))

    return left

  def leftRotate(self, node: Optional[Node]) -> Node:
    right, rightL = node.right, node.right.left  # guaranteed to have a right node

    right.left = node
    node.right = rightL

    # Updating heights
    node.height = 1 + max(self.height(node.left), self.height(node.right))
    right.height = 1 + max(self.height(right.left), self.height(right.right))

    return right
