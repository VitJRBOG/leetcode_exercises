#include <vector>

class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int16_t profit = 0;
        int16_t maxPrice = 0;

        for (int32_t i = prices.size() - 1; 0 <= i; i--) {
            if (maxPrice < prices[i]) {
                maxPrice = prices[i];
            } else if (profit < maxPrice - prices[i]) {
                profit = maxPrice - prices[i];
            }
        }

        return profit;
    }
};