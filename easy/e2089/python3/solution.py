from typing import List


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(0, len(nums)-1-i, 1):
                if nums[j+1] < nums[j]:
                    nums[j+1], nums[j] = nums[j], nums[j+1]

        result = []

        for i in range(len(nums)):
            if nums[i] == target:
                result.append(i)

        return result
