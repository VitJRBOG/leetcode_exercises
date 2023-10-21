class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0

        negative = False
        if dividend < 0 and divisor > 0:
            negative = True
            dividend = abs(dividend)
        elif divisor < 0 and dividend > 0:
            negative = True
            divisor = abs(divisor)
        elif dividend < 0 and divisor < 0:
            dividend = abs(dividend)
            divisor = abs(divisor)

        result = 0
        mask = 1

        while dividend >= divisor and divisor > 0:
            mask <<= 1
            divisor <<= 1

        while mask > 1:
            mask >>= 1
            divisor >>= 1
            if dividend >= divisor:
                dividend -= divisor
                result |= mask

        if negative:
            result = result - result - result

        if result > 2147483647:
            result = 2147483647
        elif result < -2147483648:
            result = -2147483648

        return result
