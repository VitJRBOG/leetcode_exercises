#include <iostream>
#include <vector>

class Solution {
   public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int32_t x = cost[0];
        int32_t y = cost[1];
        int32_t z = 0;

        for (int16_t i = 2; i < cost.size(); i++) {
            if (x < y) {
                z = cost[i] + x;
            } else {
                z = cost[i] + y;
            }

            x = y;
            y = z;
        }

        if (x < y) {
            return x;
        } else {
            return y;
        }
    }
};