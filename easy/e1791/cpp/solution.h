#include <iostream>
#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        if (edges.size() == 2) {
            if (edges[0][0] == edges[1][0]) {
                return edges[0][0];
            }

            if (edges[0][1] == edges[1][1]) {
                return edges[0][1];
            }

            if (edges[0][1] == edges[1][0]) {
                return edges[0][1];
            }

            if (edges[0][0] == edges[1][1]) {
                return edges[0][0];
            }
        }

        if (edges[0][0] == edges[1][0] && edges[1][0] == edges[2][0]) {
            return edges[0][0];
        }

        if (edges[0][0] == edges[1][0] && edges[1][0] == edges[2][1]) {
            return edges[0][0];
        }

        if (edges[0][0] == edges[1][1] && edges[1][1] == edges[2][0]) {
            return edges[0][0];
        }

        if (edges[0][0] == edges[1][1] && edges[1][1] == edges[2][1]) {
            return edges[0][0];
        }

        if (edges[0][1] == edges[1][0] && edges[1][0] == edges[2][0]) {
            return edges[0][1];
        }

        if (edges[0][1] == edges[1][0] && edges[1][0] == edges[2][1]) {
            return edges[0][1];
        }

        if (edges[0][1] == edges[1][1] && edges[1][1] == edges[2][0]) {
            return edges[0][1];
        }

        if (edges[0][1] == edges[1][1] && edges[1][1] == edges[2][1]) {
            return edges[0][1];
        }

        return -1;
    }
};