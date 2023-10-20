class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        origX = x
        n = 0

        while x > 0:
            n = (n * 10) + (x % 10)

            x = x // 10

        if origX == n:
            return True
        else:
            return False
