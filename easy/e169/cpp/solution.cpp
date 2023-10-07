#include <iostream>
#include <map>
#include <vector>

class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return nums[0];
        }

        std::map<int32_t, int16_t> counter;

        for (int32_t n : nums) {
            if (counter.count(n) == 0) {
                counter[n] = 1;
            } else {
                counter[n]++;
            }

            if (counter[n] > nums.size() / 2) {
                return n;
            }
        }

        return 0;
    }
};

int main() {
    std::vector<std::vector<int>> input = {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}};

    std::vector<int> expectations = {3, 2};

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

        int result = s.majorityElement(input[i]);

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