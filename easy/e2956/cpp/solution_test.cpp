#include "solution.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> input1 = {{4, 3, 2, 3, 1}};
    std::vector<std::vector<int>> input2 = {{2, 2, 5, 2, 3, 6}};

    assert(1 <= input1.size() and input1.size() <= 100);
    assert(1 <= input2.size() and input2.size() <= 100);

    std::vector<std::vector<int>> expectations = {{3, 4}};

    if (input1.size() != input2.size() || input2.size() != expectations.size() ||
        expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        std::vector<int> origInput1(input1[i].size());
        std::vector<int> origInput2(input2[i].size());

        for (int k = 0; k < origInput1.size(); k++) {
            assert(0 <= input1[i][k] and input1[i][k] <= 100);
            assert(0 <= input2[i][k] and input2[i][k] <= 100);

            origInput1[k] = input1[i][k];
            origInput2[k] = input2[i][k];
        }

        std::vector<int> result = s.findIntersectionValues(input1[i], input2[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";
            for (int j = 0; j < origInput1.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << origInput1[j];
            }
            std::cerr << "] and [";
            for (int j = 0; j < origInput2.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << origInput2[j];
            }
            std::cerr << "]: got [";
            for (int j = 0; j < result.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << result[j];
            }

            std::cerr << "] expected [";
            for (int j = 0; j < expectations[i].size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << expectations[i][j];
            }
            std::cerr << "]\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}
