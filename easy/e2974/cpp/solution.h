#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> numberGame(std::vector<int>& nums) {
        int8_t alice;
        int8_t bob;
        int8_t tmp;

        std::vector<int> result(nums.size());

        int8_t i = 0;
        while (i < nums.size()) {
            alice = -1;
            bob = -1;

            for (int8_t j = 0; j < nums.size(); j++) {
                if (-1 == nums[j]) {
                    continue;
                }

                if (alice == -1) {
                    alice = j;
                    continue;
                } else if (bob == -1) {
                    bob = j;
                    continue;
                }

                if (nums[j] < nums[alice]) {
                    if (nums[alice] < nums[bob]) {
                        bob = alice;
                    }
                    alice = j;
                } else if (nums[j] < nums[bob]) {
                    bob = j;
                }
            }

            if (nums[bob] < nums[alice]) {
                tmp = bob;
                bob = alice;
                alice = tmp;
            }

            result[i] = nums[bob];
            nums[bob] = -1;
            i++;

            result[i] = nums[alice];
            nums[alice] = -1;
            i++;
        }

        return result;
    }
};