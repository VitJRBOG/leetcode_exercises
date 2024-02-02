#include <iostream>
#include <map>
#include <vector>

class Solution {
   public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::map<int, int> mNums1;
        std::map<int, int> mNums2;
        uint8_t i;

        for (i = 0; i < nums1.size(); i++) {
            if (mNums1.count(nums1[i]) == 0) {
                mNums1[nums1[i]] = 0;
            }
        }

        for (i = 0; i < nums2.size(); i++) {
            if (mNums2.count(nums2[i]) == 0) {
                mNums2[nums2[i]] = 0;
            }

            if (mNums1.count(nums2[i]) == 1) {
                mNums1[nums2[i]]++;
            }
        }

        for (i = 0; i < nums1.size(); i++) {
            if (mNums2.count(nums1[i]) == 1) {
                mNums2[nums1[i]]++;
            }
        }

        std::vector<int> result = {0, 0};
        auto it = mNums1.begin();

        for (; it != mNums1.end(); it++) {
            result[1] = result[1] + it->second;
        }

        it = mNums2.begin();

        for (; it != mNums2.end(); it++) {
            result[0] = result[0] + it->second;
        }

        return result;
    }
};