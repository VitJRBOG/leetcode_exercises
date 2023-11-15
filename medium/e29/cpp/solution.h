#include <iostream>

class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }

        bool negative = dividend < 0 xor divisor < 0;

        uint32_t uDividend = abs(dividend);
        uint32_t uDivisor = abs(divisor);

        if (uDividend < uDivisor) {
            return 0;
        } else if (uDividend == uDivisor) {
            return negative ? -1 : 1;
        }

        uint32_t result = 0;

        while (uDivisor <= uDividend) {
            int32_t q = 0;
            while ((uDivisor << (q + 1)) < uDividend) {
                q++;
            }

            result += 1 << q;

            uDividend -= uDivisor << q;
        }

        if (negative) {
            if (2147483648 < result) {
                result = 2147483648;
            }
            return 0 - result;
        } else {
            if (2147483647 < result) {
                result = 2147483647;
            }
        }

        return result;
    }
};