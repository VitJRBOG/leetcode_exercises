#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> input1 = {
        {1, 2, 5}, {2}, {1}, {1}, {1}, {2, 5, 10, 1}, {186,419,83,408}, {37,233,253,483}, {1, 2, 5, 7, 10, 13, 15, 20, 21, 25, 30, 31} };
    std::vector<int> input2 = { 11, 3, 0, 1, 2, 27, 6249, 7163, 1000 };

    std::vector<int> expectations = { 3, -1, 0, 1, 2, 4, 20, 19, 33 };

    if (input1.size() != input2.size() || input2.size() != expectations.size() ||
        expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(0 <= input2[i] && input2[i] <= pow(10, 4));

        assert(1 <= input1[i].size() && input1[i].size() <= 12);
        std::vector<int> origInput1(input1[i].size());
        for (int j = 0; j < origInput1.size(); j++) {
            assert(1 <= input1[i][j] && input1[i][j] <= (pow(2, 31) - 1));
            origInput1[j] = input1[i][j];
        }

        int result = s.coinChange(input1[i], input2[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < origInput1.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }

                std::cerr << origInput1[j];
            }

            std::cerr << "] and " << input2[i];

            std::cerr << ": got " << result;
            std::cerr << " expected " << expectations[i] << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}