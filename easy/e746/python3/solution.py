from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        result = [cost[0], cost[1]] + [0] * (len(cost) - 2)

        for i in range(2, len(cost), 1):
            result[i] = cost[i] + min(result[i-1], result[i-2])

        return min(result[-1], result[-2])
