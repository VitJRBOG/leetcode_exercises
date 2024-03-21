#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<std::vector<int>>> input1 = { {{1,2},{3},{3},{}}, {{4,3,1},{3,2,4},{3},{4},{}} };
    std::vector<std::vector<std::vector<int>>> expectations = { {{0,1,3},{0,2,3}}, {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}} };

    if (input1.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    std::cout << "Running tests for " << expectations.size() << " cases..." << std::endl;

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(2 <= input1[i].size() && input1[i].size() <= 15);
        std::vector<std::vector<int>> origInput;

        for (int j = 0; j < input1[i].size(); j++) {
            origInput.push_back({});
            for (int k = 0; k < input1[i][j].size(); k++) {
                assert(0 <= input1[i][j][k] && input1[i][j][k] < input1[i].size());
                origInput[j].push_back(input1[i][j][k]);
            }
        }

        std::vector<std::vector<int>> result = s.allPathsSourceTarget(input1[i]);

        bool isFailed = false;

        if (result.size() != expectations[i].size()) {
            isFailed = true;
        } else {
            for (int j = 0; j < result.size(); j++) {
                if (result[j].size() != expectations[i][j].size()) {
                    isFailed = true;
                    break;
                }
                for (int k = 0; k < result[j].size(); k++) {
                    if (result[j][k] != expectations[i][j][k]) {
                        isFailed = true;
                        break;
                    }
                }
                if (isFailed) {
                    break;
                }
            }
        }

        if (isFailed) {
            std::cerr << "#" << i << " FAILED";
            std::cerr << ": bad result for [";

            for (int j = 0; j < origInput.size(); j++) {
                if (0 < j) {
                    std::cerr << ", ";
                }
                std::cerr << "[";

                for (int k = 0; k < origInput[j].size(); k++) {
                    if (0 < k) {
                        std::cerr << ", ";
                    }
                    std::cerr << origInput[j][k];
                }

                std::cerr << "]";
            }

            std::cerr << "]";
            std::cerr << ": got [";

            for (int j = 0; j < result.size(); j++) {
                if (0 < j) {
                    std::cerr << ", ";
                }
                std::cerr << "[";

                for (int k = 0; k < result[j].size(); k++) {
                    if (0 < k) {
                        std::cerr << ", ";
                    }
                    std::cerr << result[j][k];
                }

                std::cerr << "]";
            }

            std::cerr << "] expected [";

            for (int j = 0; j < expectations[i].size(); j++) {
                if (0 < j) {
                    std::cerr << ", ";
                }
                std::cerr << "[";

                for (int k = 0; k < expectations[i][j].size(); k++) {
                    if (0 < k) {
                        std::cerr << ", ";
                    }
                    std::cerr << expectations[i][j][k];
                }

                std::cerr << "]";
            }

            std::cerr << "]" << std::endl;
        } else {
            std::cout << "#" << i << " PASSED" << std::endl;
        }
    }

    return 0;
}