#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> input1 = { 3, 6, 5, 1, 3, 10, 10 };
    std::vector<std::vector<std::vector<int>>> input2 = { {{0,1},{1,2},{2,0}}, {{0,1},{0,2},{3,5},{5,4},{4,3}},
        {{0,4}}, {}, {{0,1},{1,2},{2,0}}, {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}},
        {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}} };
    std::vector<int> input3 = { 0, 0, 0, 0, 0, 5, 7 };
    std::vector<int> input4 = { 2, 5, 4, 0, 0, 9, 5 };
    std::vector<bool> expectations = { true, false, true, true, true, true, true };

    if (input1.size() != input2.size() || input2.size() != input3.size() || input3.size() != input4.size()
        || input4.size() != expectations.size() || expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    std::cout << "Running tests for " << expectations.size() << " cases..." << std::endl;

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(1 <= input1[i] || input1[i] <= 2 * pow(10, 5));
        assert(0 <= input2[i].size() || input2[i].size() <= 2 * pow(10, 5));

        std::vector<std::vector<int>> origInput;

        for (int j = 0; j < input2[i].size(); j++) {
            assert(input2[i][j].size() == 2);
            assert(input2[i][j][0] != input2[i][j][1]);

            origInput.push_back(std::vector<int>{ input2[i][j][0], input2[i][j][1] });
        }

        bool result = s.validPath(input1[i], input2[i], input3[i], input4[i]);

        if (result != expectations[i]) {
            std::cerr << "#" << i << " FAILED";
            std::cerr << ": bad result for " << std::boolalpha << input1[i];
            std::cerr << ", [";

            for (int j = 0; j < origInput.size(); j++) {
                if (0 < j) {
                    std::cerr << ", ";
                }

                std::cerr << "[" << origInput[j][0];
                std::cerr << ", " << origInput[j][1];
                std::cerr << "]";
            }

            std::cerr << "], " << input3[i];
            std::cerr << ", and " << input4[i];
            std::cerr << ": got " << result;
            std::cerr << " expected " << expectations[i];
            std::cerr << std::endl;
        } else {
            std::cout << "#" << i << " PASSED" << std::endl;
        }
    }

    return 0;
}