from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return False
        elif len(nums) == 2:
            if nums[0] == nums[1]:
                return True
            else:
                return False

        is_sorted = False
        while not is_sorted:
            is_sorted = True
            for i in range(len(nums)-1):
                if nums[i] == nums[i+1]:
                    return True
                elif nums[i] > nums[i+1]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
                    is_sorted = False

        return False
