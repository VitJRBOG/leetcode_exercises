#include <vector>

class Solution {
   public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return std::vector<int>{-1, -1};
        }

        std::vector<int> result = {-1, -1};

        int32_t left = 0;
        int32_t right = nums.size() - 1;

        while (left <= right) {
            int32_t middle = left + (right - left) / 2;

            if (nums[middle] == target) {
                if (middle == 0 or nums[middle - 1] < target) {
                    result[0] = middle;
                    if (middle == nums.size() - 1 or nums[middle + 1] > target) {
                        result[1] = middle;
                        break;
                    }
                    left = middle + 1;
                } else if (middle == nums.size() - 1 or nums[middle + 1] > target) {
                    result[1] = middle;
                    if (middle == 0 or nums[middle - 1] < target) {
                        result[0] = middle;
                        break;
                    }
                    right = middle - 1;
                } else {
                    left = middle - 1;
                    right = middle + 1;
                    while (true) {
                        if (result[0] == -1) {
                            if ((nums[left] == target) and (left == 0 or nums[left - 1] < target)) {
                                result[0] = left;
                            } else {
                                left--;
                            }
                        }

                        if (result[1] == -1) {
                            if ((nums[right] == target) and
                                (right == nums.size() - 1 or target < nums[right + 1])) {
                                result[1] = right;
                            } else {
                                right++;
                            }
                        }

                        if (result[0] != -1 and result[1] != -1) {
                            break;
                        }
                    }
                }

                if (result[0] != -1 and result[1] != -1) {
                    break;
                }
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return result;
    }
};