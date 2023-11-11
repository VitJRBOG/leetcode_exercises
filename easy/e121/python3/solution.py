from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0

        max_price = 0
        profit = 0

        for i in range(len(prices)-1, -1, -1):
            if max_price < prices[i]:
                max_price = prices[i]
            elif profit < max_price - prices[i]:
                profit = max_price - prices[i]

            i += 1

        return profit
