class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while True:
            if n == 1:
                return True
            elif n % 3 != 0:
                return False

            n = int(n / 3)

            if n < 1:
                return False
