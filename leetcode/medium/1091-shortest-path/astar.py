"""
  @author Vortexx2
  Problem 1091 - Shortest Path in a Binary Matrix

  Runtime - 1579 ms O(n ^ 2)
  Memory Usage - 15.9 MB O(n ^ 2)
"""
from typing import List, Tuple
from dataclasses import dataclass, field
from heapq import heappush, heappop


class PriorityQueue:

  def __init__(self):
    self.heap = []

  def add(self, value, priority=0):
    heappush(self.heap, (priority, value))

  def pop(self):
    _, value = heappop(self.heap)
    return value

  def empty(self):
    return len(self.heap) == 0


class Solution:

  def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:

    if grid[0][0] or grid[-1][-1]:
      return -1

    n = len(grid)

    def heuristic(row: int, col: int) -> int:
      return max(n - 1 - row, n - 1 - col)

    def get_successors(node: Tuple[int, int]) -> List[Tuple[int, int]]:
      """
        Returns list of child nodes and adds priority = dist + heuristic
      """
      res = []

      dirs = [(1, 1), (1, 0), (0, 1), (1, -1),
              (-1, 1), (0, -1), (-1, 0), (-1, -1)]

      for (x, y) in dirs:

        nx, ny = node[0] + x, node[1] + y

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
          continue

        if grid[nx][ny]: continue

        res.append((nx, ny))

      return res

    def is_goal(node: Tuple[int, int]) -> bool:
      """Checks if node is goal node"""
      return node[0] == n - 1 and node[1] == n - 1

    def astar(start: tuple):

      frontier = PriorityQueue()

      frontier.add(start, priority=1)

      visited = set()
      dist = {start: 1}

      while not frontier.empty():
        curr = frontier.pop()

        if curr in visited:
          continue

        if is_goal(curr):
          return dist[curr]

        visited.add(curr)

        children = get_successors(curr)

        for child in children:

          frontier.add(child, priority=dist[curr] + 1 + heuristic(*child))

          if child not in dist or dist[child] > dist[curr] + 1:
            dist[child] = dist[curr] + 1

      return -1

    return astar((0, 0))
