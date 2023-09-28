#include <iostream>

class Solution {
   public:
    int reverse(int x) {
        int64_t n = 0;

        while (true) {
            if (n != 0) {
                n *= 10;
            }

            n += x % 10;
            x /= 10;

            if (x == 0) {
                break;
            }
        }

        if (n < -2147483648 or n > 2147483647) {
            return 0;
        }

        return n;
    }
};

int main() {
    Solution s;

    int input[6] = {123, -123, 120, 1534236469, -2147483648, -2147483412};
    int expectations[6] = {321, -321, 21, 0, 0, -2143847412};

    for (int i = 0; i < 6; i++) {
        auto result = s.reverse(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for " << input[i] << ": got "
                      << result << " expected " << expectations[i] << "\n";
            return 0;
        }
    }

    std::cout << "PASS\n";

    return 0;
}