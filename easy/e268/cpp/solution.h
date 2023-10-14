#include <iostream>
#include <vector>

class Solution {
   public:
    int missingNumber(std::vector<int>& nums) {
        if (nums.size() == 1) {
            if (nums[0] == 0) {
                return 1;
            } else {
                return nums[0] - 1;
            }
        }

        int16_t tail = 0;
        int16_t counter = 0;
        for (int16_t i = 0; i < nums.size(); i++) {
            if (nums[i] == counter) {
                nums[i] = nums[tail];
                nums[tail] = counter;
                counter++;
                tail++;
            } else {
                continue;
            }

            i = tail - 1;
        }

        return counter;
    }
};