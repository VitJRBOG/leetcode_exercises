#include <iostream>
#include <vector>

class Solution {
   public:
    int singleNumber(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        uint16_t i = 0;
        uint16_t j = i + 1;

        while (true) {
            if (i > nums.size() - 2) {
                return nums[nums.size() - 1];
            }

            if (j > nums.size() - 1) {
                return nums[i];
            }

            if (nums[i] == nums[j]) {
                if (j > i + 1) {
                    int32_t tmp = nums[i + 1];
                    nums[i + 1] = nums[j];
                    nums[j] = tmp;
                }

                i += 2;
                j = i + 1;
                continue;
            }

            j++;
        }
    }
};

int main() {
    std::vector<std::vector<int>> input = {
        {2, 2, 1}, {4, 1, 2, 1, 2}, {1}, {1, 0, 1}, {-1, 0, 5, -1, 4, 6, 7, 4, 6, 0, 5}};

    std::vector<int> expectations = {1, 4, 1, 0, 7};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        std::vector<int> origInput(input[i].size());

        for (int k = 0; k < origInput.size(); k++) {
            origInput[k] = input[i][k];
        }

        int result = s.singleNumber(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for";
            for (int j = 0; j < origInput.size(); j++) {
                std::cerr << " " << origInput[j];
            }
            std::cerr << ": got " << result << " expected " << expectations[i] << "\n";
            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}