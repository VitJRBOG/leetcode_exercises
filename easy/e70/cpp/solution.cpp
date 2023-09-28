#include <iostream>

class Solution {
   public:
    int climbStairs(int n) {
        int32_t x = 1;
        int32_t y = 1;

        for (; n > 1; n--) {
            auto tmp = y;
            y = x + y;
            x = tmp;
        }

        return y;
    }
};

int main() {
    int input[5] = {2, 3, 4, 5, 45};
    int expectations[5] = {2, 3, 5, 8, 1836311903};

    for (int i = 0; i < 5; i++) {
        Solution s;

        auto result = s.climbStairs(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for " << input[i] << ": got "
                      << result << " expected " << expectations[i] << "\n";
            return 0;
        }
    }

    std::cout << "PASS\n";

    return 0;
}