"""
  @author Vortexx2

  Runtime - 56 ms
  Memory Usage - 15.1 MB
"""
from typing import List


class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    max_sum = nums[0]
    curr_sum = nums[0]

    for i in range(1, len(nums)):

      temp = curr_sum + nums[i]

      if nums[i] > temp:
        curr_sum = nums[i]

      else:
        curr_sum = temp

      max_sum = max(max_sum, curr_sum)

    return max_sum


if __name__ == '__main__':
  sol = Solution()
  print(sol.maxSubArray([5, 4, -1, 7, 8]))
