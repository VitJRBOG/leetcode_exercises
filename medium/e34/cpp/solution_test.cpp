#include "solution.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> input1 = {{5, 7, 7, 8, 8, 10},
                                            {5, 7, 7, 8, 8, 10},
                                            {},
                                            {1},
                                            {5, 6, 7, 8, 9},
                                            {1, 2, 3},
                                            {1, 4},
                                            {1, 4},
                                            {1, 2, 3, 3, 3, 4, 5},
                                            {3, 3, 3},
                                            {1, 2, 3, 3, 3, 3, 4, 5, 9},
                                            {0, 0, 0, 1, 2, 3},
                                            {0, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 9},
                                            {0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9}};
    std::vector<int> input2 = {8, 6, 0, 1, 7, 0, 1, 4, 3, 3, 3, 0, 7, 1};

    std::vector<std::vector<int>> expectations = {{3, 4},   {-1, -1}, {-1, -1}, {0, 0}, {2, 2},
                                                  {-1, -1}, {0, 0},   {1, 1},   {2, 4}, {0, 2},
                                                  {2, 5},   {0, 2},   {15, 17}, {1, 3}};

    if (input1.size() != input2.size() or input2.size() != expectations.size() or
        expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(0 <= input1[i].size() and input1[i].size() <= std::pow(10, 5));
        assert(std::pow(10, 9) * -1 <= input2[i] and input2[i] <= std::pow(10, 9));

        std::vector<int> origInput(input1[i].size());

        for (int j = 0; j < origInput.size(); j++) {
            assert(std::pow(10, 9) * -1 <= input1[i][j] and input1[i][j] <= std::pow(10, 9));

            origInput[j] = input1[i][j];
        }

        std::vector<int> result = s.searchRange(input1[i], input2[i]);

        if (result.size() != expectations[i].size()) {
            std::cerr << "FAIL: bad result for";
            for (int n = 0; n < origInput.size(); n++) {
                std::cerr << " " << origInput[n];
            }
            std::cerr << " and " << input2[i];

            std::cerr << ": got";
            for (int n = 0; n < result.size(); n++) {
                std::cerr << " " << result[n];
            }

            std::cerr << " expected";
            for (int n = 0; n < expectations[i].size(); n++) {
                std::cerr << " " << expectations[i][n];
            }

            std::cerr << "\n";
            return 0;
        }

        for (int j = 0; j < expectations[i].size(); j++) {
            if (result[j] != expectations[i][j]) {
                std::cerr << "FAIL: bad result for";
                for (int n = 0; n < origInput.size(); n++) {
                    std::cerr << " " << origInput[n];
                }
                std::cerr << " and " << input2[i];

                std::cerr << ": got";
                for (int n = 0; n < result.size(); n++) {
                    std::cerr << " " << result[n];
                }

                std::cerr << " expected";
                for (int n = 0; n < expectations[i].size(); n++) {
                    std::cerr << " " << expectations[i][n];
                }

                std::cerr << "\n";
                return 0;
            }
        }
    }

    std::cout << "PASS";

    return 0;
}
