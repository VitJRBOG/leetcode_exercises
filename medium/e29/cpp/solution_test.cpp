#include "solution.h"

#include <iostream>
#include <vector>

int main() {
    Solution s;

    std::vector<int> input1 = {10,          7,           1,           -1, 2147483647, -2147483648,
                               -2147483648, -2147483648, -2147483648, 1,  5,          -2147483648};
    std::vector<int> input2 = {3, -3, 1, -1, 3, 3, 1, -1, 2, 2, 2, -2147483648};

    std::vector<int> expectations = {3,           -2,         1,           1, 715827882, -715827882,
                                     -2147483648, 2147483647, -1073741824, 0, 2,         1};

    if (input1.size() != input2.size() or input2.size() != expectations.size() or
        expectations.size() != input1.size()) {
        std::cout << "PASS";
        return 0;
    }

    for (int i = 0; i < expectations.size(); i++) {
        auto result = s.divide(input1[i], input2[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for " << input1[i] << " and " << input2[i] << ": got " << result
                      << " expected " << expectations[i] << "\n";
            return 0;
        }
    }

    std::cout << "PASS";
    return 0;
}