"""
  @author Vortexx2

  Runtime - 1736 ms
  Memory Usage - 30.7 MB
"""
from typing import Deque, List
from collections import deque


class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:

    if not len(nums) or k == 1 or len(nums) == 1:
      return nums

    res = []
    dq = deque([])

    for i in range(k):
      while (len(dq) and nums[dq[-1]] < nums[i]):
        dq.pop()

      dq.append(i)

    for i in range(k, len(nums)):

      res.append(nums[dq[0]])

      while (len(dq) and nums[dq[-1]] < nums[i]):
        dq.pop()

      while (len(dq) and dq[0] + k <= i):
        dq.popleft()

      dq.append(i)

    res.append(nums[dq[0]])

    return res


if __name__ == "__main__":

  sol = Solution()
  print(sol.maxSlidingWindow([1, 3, 1, 2, 0, 5], 3))
