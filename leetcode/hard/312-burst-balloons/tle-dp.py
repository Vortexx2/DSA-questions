"""
    author Vortexx2
    DP solution that is TLE
"""
from typing import List


def get_arr(nums: List[int], idx: int):
    n = len(nums)

    if idx < 0 or idx >= n:
        return 1

    return nums[idx]


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        self.dp = {}

        return self.helper(nums)

    def helper(self, nums: List[int]) -> int:
        # 3, 1, 5, 8
        if len(nums) == 1:
            return nums[0]

        if str(nums) in self.dp:
            return self.dp[str(nums)]

        res = -1e8
        for i in range(len(nums)):
            curr_score = get_arr(nums, i - 1) * get_arr(nums, i) * get_arr(nums, i + 1)
            curr_pop = nums.pop(i)
            curr_max = self.maxCoins(nums) + curr_score
            nums.insert(i, curr_pop)

            res = max(res, curr_max)

        self.dp[str(nums)] = res

        return res
