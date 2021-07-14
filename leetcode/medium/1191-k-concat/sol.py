from typing import List


class Solution:
  def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
    summ = 0

    for num in arr:
      
      if num > 0:
        summ += num
    
    return int((summ * k) % (1e9 + 7))

