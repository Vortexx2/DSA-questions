from typing import List


class Solution:
  def findCircleNum(self, isConnected: List[List[int]]) -> int:

    def dfs(pos: int) -> None:

      if visited[pos]:
        return

      visited[pos] = True

      for i in range(n):
        if isConnected[pos][i]:
          dfs(i)

    n = len(isConnected)

    visited = [False] * n

    res = 0

    for i in range(n):
      for j in range(n):

        if visited[i]:
          break

        if i == j:
          continue

        visited[i] = True
        if isConnected[i][j]:
          dfs(j)

        visited[i] = False

      if not visited[i]:
        res += 1

      visited[i] = True

    return res
