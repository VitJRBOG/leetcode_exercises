from typing import List


class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        binary_numbers = [""] * len(arr)

        for i in range(len(arr)):
            binary_numbers[i] = bin(arr[i])[2:]

            target = binary_numbers[i]

            j = i
            while 0 < j and target.count("1") < binary_numbers[j-1].count("1"):
                binary_numbers[j] = binary_numbers[j-1]
                j -= 1
            binary_numbers[j] = target

        numbers = [0] * len(binary_numbers)

        for i in range(len(binary_numbers)):
            numbers[i] = int(binary_numbers[i], base=2)

            right = i
            left = 0
            while 0 <= i and binary_numbers[i].count("1") == binary_numbers[right].count("1"):
                left = i
                i -= 1

            for i in range(left, right, 1):

                target = numbers[right]

                j = right
                while left < j and target < numbers[j-1]:
                    numbers[j] = numbers[j-1]
                    j -= 1

                numbers[j] = target

        return numbers
