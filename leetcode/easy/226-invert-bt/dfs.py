"""
  @author Vortexx2
  Problem 226 - Invert BT

  Runtime - 28 ms
  Memory Usage - 14.3 MB
"""
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def invertTree(self, root: TreeNode) -> TreeNode:
    if not root:
      return None
    
    st = [root]

    while st:
      node = st.pop()
      temp = node.left
      node.left = node.right
      node.right = temp

      if node.left:
        st.append(node.left)
      
      if node.right:
        st.append(node.right)

    return root