#include "solution.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::vector<int>> input = {{1, 3, 5, 4, 7}, {2, 2, 2, 2, 2}};

    std::vector<int> expectations = {3, 1};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        assert(1 <= input[i].size() and input[i].size() <= pow(10, 4));

        std::vector<int> origInput(input[i].size());

        for (int k = 0; k < origInput.size(); k++) {
            assert(-pow(10, 9) <= input[i][k] and input[i][k] <= pow(10, 9));

            origInput[k] = input[i][k];
        }

        int result = s.findLengthOfLCIS(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";
            for (int j = 0; j < origInput.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << origInput[j];
            }
            std::cerr << "]: got " << result << " expected " << expectations[i] << "\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}