#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> input1 = { {5,4,2,3}, {2,5}, {5,4,2,3,6,1,7,8}, {4,4,3,8} };

    std::vector<std::vector<int>> expectations = { {3,2,5,4}, {5,2}, {2,1,4,3,6,5,8,7}, {4,3,8,4} };

    if (input1.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(1 <= input1[i].size() && input1[i].size() <= 100);
        assert(input1[i].size() % 2 == 0);

        std::vector<int> origInput1(input1[i].size());
        for (int j = 0; j < origInput1.size(); j++) {
            assert(1 <= input1[i][j] && input1[i][j] <= 100);
            origInput1[j] = input1[i][j];
        }

        std::vector<int> result = s.numberGame(input1[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < origInput1.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }

                std::cerr << origInput1[j];
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

            std::cerr << "]" << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}