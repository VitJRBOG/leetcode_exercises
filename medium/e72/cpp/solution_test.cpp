#include "solution.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> input1 = {"horse", "intention", ""};
    std::vector<std::string> input2 = {"ros", "execution", ""};

    std::vector<int> expectations = {3, 5, 0};

    if (input1.size() != input2.size() || input2.size() != expectations.size() ||
        expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(0 <= input1[i].size() and input1[i].size() <= 500);
        assert(0 <= input2[i].size() and input2[i].size() <= 500);

        int result = s.minDistance(input1[i], input2[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for \"" << input1[i] << "\" and \"" << input2[i];

            std::cerr << "\": got " << result;
            std::cerr << " expected " << expectations[i] << "\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}