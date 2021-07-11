from typing import List

class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    result = [0] * len(nums) - k + 1

    


