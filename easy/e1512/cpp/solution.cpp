#include <iostream>
#include <vector>

class Solution {
   public:
    int numIdenticalPairs(std::vector<int>& nums) {
        uint16_t pair_counter = 0;

        for (uint8_t i = 0; i < nums.size(); i++) {
            for (uint8_t j = i + 1; j < nums.size(); j++) {
                if (i >= j) {
                    continue;
                }
                if (nums[i] == nums[j]) {
                    pair_counter++;
                }
            }
        }

        return pair_counter;
    }
};

int main() {
    std::vector<std::vector<int>> input = {
        {1, 2, 3, 1, 1, 3},
        {1, 1, 1, 1},
        {1, 2, 3},
        {7, 1, 5, 7, 8, 5, 6, 8, 4, 7, 2, 7, 3, 3, 5, 7, 2, 2, 2, 7, 2, 4, 7, 3, 1,
         2, 7, 7, 5, 6, 6, 1, 8, 5, 4, 7, 6, 1, 4, 7, 7, 6, 5, 2, 2, 4, 5, 2, 2},
        {3,  1, 10, 2, 4, 8, 3, 2,  9, 5,  4,  8, 4, 3,  1,  5, 5,  7, 2, 2, 8, 8, 10, 1, 7,
         10, 5, 10, 2, 9, 8, 7, 10, 3, 10, 10, 9, 8, 10, 7,  3, 10, 2, 9, 8, 3, 1, 2,  1, 6,
         4,  9, 7,  5, 6, 7, 4, 5,  3, 1,  4,  2, 2, 1,  10, 4, 2,  7, 3, 6, 5, 7, 3,  10}};

    std::vector<int> expectations = {4, 6, 0, 164, 261};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        int result = s.numIdenticalPairs(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for";
            for (int j = 0; j < input[i].size(); j++) {
                std::cerr << " " << input[i][j];
            }
            std::cerr << ": got " << result << " expected " << expectations[i] << "\n";
            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}