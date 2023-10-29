from typing import List


class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        counter = {}

        minimal = nums[0]
        maximal = nums[-1]

        for i in range(len(nums)):
            if nums[i] < minimal:
                minimal = nums[i]
            elif maximal < nums[i]:
                maximal = nums[i]

            if nums[i] not in counter:
                counter[nums[i]] = 1
            else:
                counter[nums[i]] += 1

        pos = 0

        for i in range(minimal, maximal+1, 1):
            if i not in counter:
                continue

            while counter[i] > 0:
                nums[pos] = i
                counter[i] -= 1
                pos += 1

        if nums[-1] * nums[-2] * nums[-3] < nums[0] * nums[1] * nums[-1]:
            return nums[0] * nums[1] * nums[-1]

        return nums[-1] * nums[-2] * nums[-3]
