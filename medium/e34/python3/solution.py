from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        elif len(nums) == 1:
            if nums[0] == target:
                return [0, 0]
            else:
                return [-1, -1]

        result = [-1, -1]

        leftEdge = 0
        rightEdge = len(nums)-1

        while (leftEdge <= rightEdge):
            middle = int(leftEdge + (rightEdge - leftEdge) / 2)

            if nums[middle] == target:
                if middle == 0 or nums[middle - 1] < target:
                    result[0] = middle
                    if middle == len(nums) - 1 or target < nums[middle+1]:
                        result[1] = middle
                        break
                    else:
                        leftEdge = middle + 1
                elif middle == len(nums) - 1 or target < nums[middle+1]:
                    result[1] = middle
                    if middle == 0 or nums[middle - 1] < target:
                        result[0] = middle
                        break
                    else:
                        rightEdge = middle - 1
                else:
                    if nums[0] == target:
                        result[0] = 0

                    if nums[len(nums)-1] == target:
                        result[1] = len(nums)-1

                    leftEdge = middle - 1
                    rightEdge = middle + 1
                    while (result[0] == -1 or result[1] == -1):
                        if result[0] == -1:
                            if nums[leftEdge] < target:
                                result[0] = leftEdge+1
                            else:
                                leftEdge -= 1

                        if result[1] == -1:
                            if target < nums[rightEdge]:
                                result[1] = rightEdge-1
                            else:
                                rightEdge += 1

                    break

            elif nums[middle] < target:
                leftEdge = middle + 1
            else:
                rightEdge = middle - 1

        return result
