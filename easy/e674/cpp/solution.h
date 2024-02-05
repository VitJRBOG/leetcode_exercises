#include <iostream>
#include <vector>

class Solution {
   public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        int16_t len = nums.size();

        if (len == 1) {
            return 1;
        }

        int16_t maxSeqLen = 1;
        int16_t curSeqLen = 1;

        for (int16_t i = len - 1; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                curSeqLen++;
            }

            if (maxSeqLen < curSeqLen) {
                maxSeqLen = curSeqLen;
            }

            if (nums[i] <= nums[i - 1]) {
                curSeqLen = 1;
            }
        }

        return maxSeqLen;
    }
};