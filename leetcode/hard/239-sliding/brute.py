from typing import List


class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    res = []

    for i in range(0, len(nums) - k + 1):
      mx = nums[i]

      for i in range(i, i + k):
        print(i)
        mx = max(mx, nums[i])

      res.append(mx)

    return res


if __name__ == "__main__":
  sol = Solution()
  print(sol.maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))
