from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums), 1):
            for j in range(0, len(nums), 1):
                if i == j:
                    continue
                if nums[i] + nums[j] == target:
                    return [i, j]

        return [-1, -1]
