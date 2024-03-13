#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<std::vector<int>>> input1 = { {{1,2}, {1,3}}, {{1,2},{2,3},{4,2}}, {{1,2},{5,1},{1,3},{1,4}} };

    std::vector<int> expectations = { 1, 2, 1 };

    if (input1.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(2 <= input1[i].size() && input1[i].size() <= pow(10, 5) - 1);

        std::vector<std::vector<int>> origInput;

        for (int j = 0; j < input1[i].size(); j++) {
            assert(input1[i][j].size() == 2);
            assert(input1[i][j][0] != input1[i][j][1]);

            origInput.push_back(std::vector<int>{ input1[i][j][0], input1[i][j][1] });
        }

        int result = s.findCenter(input1[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < origInput.size(); j++) {
                if (0 < j) {
                    std::cerr << ", ";
                }

                std::cerr << "[" << origInput[j][0];
                std::cerr << ", " << origInput[j][1];
                std::cerr << "]";
            }

            std::cerr << "]: got " << result;
            std::cerr << " expected " << expectations[i];
            std::cerr << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}