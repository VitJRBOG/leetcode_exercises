#include "solution.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::vector<std::string>> input = {
        {"mass", "as", "hero", "superhero"}, {"leetcode", "et", "code"}, {"blue", "green", "bu"}};

    assert(1 <= input.size() and input.size() <= 100);

    std::vector<std::vector<std::string>> expectations = {{"as", "hero"}, {"et", "code"}, {}};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        std::vector<std::string> origInput(input[i].size());

        for (int k = 0; k < origInput.size(); k++) {
            assert(1 <= input[i][k].size() and input[i][k].size() <= 30);

            origInput[k] = input[i][k];
        }

        std::vector<std::string> result = s.stringMatching(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";
            for (int j = 0; j < origInput.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << origInput[j];
            }
            std::cerr << "]: got [";
            for (int j = 0; j < result.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << result[j];
            }

            std::cerr << "] expected [";
            for (int j = 0; j < expectations[i].size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                std::cerr << expectations[i][j];
            }
            std::cerr << "]\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}