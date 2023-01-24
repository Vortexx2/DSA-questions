"""
  @author Vortexx2
  Problem 212 - Word Search 2
  @approach Using tries

  Runtime - 1586 ms
  Memory Usage - 19.8 MB
"""
from typing import List, Deque
from collections import deque

DIRS = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
]
PLACEHOLDER = '%'


def charToInt(c: str):
  """Maps all lowercase english characters from 0-25"""
  return ord(c) - ord('a')


class TrieNode:
  val: str
  children: List["TrieNode"]
  terminal: bool
  numChildren: int

  def __init__(self, val):
    self.val = val
    self.terminal = False
    self.children = [None] * 26
    self.numChildren = 0

  def child(self, letter: str):
    return self.children[charToInt(letter)]


class Trie:
  root: TrieNode

  def __init__(self) -> None:
    self.root = TrieNode('$')

  def insert(self, word: str) -> None:

    currNode, nextNode = self.root, None

    for c in word:
      nextNode = currNode.child(c)

      if nextNode is None:
        nextNode = TrieNode(c)
        currNode.children[charToInt(c)] = nextNode
        currNode.numChildren += 1

      currNode = nextNode

    currNode.terminal = True

  def insert_multiple(self, words: str) -> None:
    for word in words:
      self.insert(word)

  def delete(self, word: str) -> None:
    """Deletes `word` if it exists, and prunes trie until it finds the last terminal node or the root"""
    stack: Deque[TrieNode] = deque([self.root])
    curr = self.root

    for c in word:
      curr = curr.child(c)

      # prefix does not even exist
      if curr is None:
        return

      stack.append(curr)

    if not curr.terminal:
      return

    curr.terminal = False

    # curr was also pushed into the stack, we need to remove it first
    stack.pop()

    # prev is one node above curr always
    prev = stack.pop()

    while curr != self.root and (not curr.terminal) and (curr.numChildren == 0):
      prev.numChildren -= 1
      prev.children[charToInt(curr.val)] = None

      # if stack is empty our work is done
      if len(stack) == 0:
        return

      curr = prev
      prev = stack.pop()


class Solution:
  def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:

    trie = Trie()
    trie.insert_multiple(words)

    m, n = len(board), len(board[0])
    res, path = [], deque()

    def dfs(x: int, y: int, node: TrieNode):

      if node.terminal:
        word = ''.join(path)
        res.append(word)

        # we need to delete the word from the trie, as well as the non terminal path that leads to that word
        trie.delete(word)

      if x < 0 or x >= m or y < 0 or y >= n or board[x][y] == PLACEHOLDER:
        return

      currChar = board[x][y]
      nextNode = node.child(currChar)

      if nextNode is None:
        return

      path.append(currChar)
      board[x][y] = PLACEHOLDER

      for dx, dy in DIRS:
        dfs(x + dx, y + dy, nextNode)

      path.pop()
      board[x][y] = currChar

    for i in range(m):
      for j in range(n):
        dfs(i, j, trie.root)

    return res
