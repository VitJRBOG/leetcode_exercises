#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        std::vector<int16_t> operations(amount + 1);

        for (int16_t i = 1; i <= amount; i++) {
            int16_t small = 32766;

            for (int8_t j = 0; j < coins.size(); j++) {
                if (coins[j] == i) {
                    small = 0;
                    break;
                }

                small = std::min(small, int16_t((coins[j] < i) ? (operations[i - coins[j]]) : (32766)));
            }

            operations[i] = 1 + small;
        }

        return (operations[amount] == 32767) ? (-1) : (operations[amount]);
    }
};