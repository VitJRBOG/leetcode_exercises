from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        x1 = cost[0]
        x2 = cost[1]
        x3 = 0

        for i in range(2, len(cost), 1):
            x3 = cost[i] + min(x1, x2)

            x1 = x2
            x2 = x3

        return min(x1, x2)
