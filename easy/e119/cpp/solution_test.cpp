#include "solution.h"

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> input = {3, 0, 1, 33};

    std::vector<std::vector<int>> expectations = {
        {1, 3, 3, 1}, {1}, {1, 1}, {1,          33,        528,       5456,       40920,      237336,
                                    1107568,    4272048,   13884156,  38567100,   92561040,   193536720,
                                    354817320,  573166440, 818809200, 1037158320, 1166803110, 1166803110,
                                    1037158320, 818809200, 573166440, 354817320,  193536720,  92561040,
                                    38567100,   13884156,  4272048,   1107568,    237336,     40920,
                                    5456,       528,       33,        1}};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        assert(0 <= input[i] and input[i] <= 33);

        std::vector<int> result = s.getRow(input[i]);

        if (result.size() != expectations[i].size()) {
            std::cerr << "FAIL: bad result for " << input[i];

            std::cerr << ": got";
            for (int j = 0; j < result.size(); j++) {
                std::cerr << " " << result[j];
            }

            std::cerr << " expected";
            for (int j = 0; j < expectations[i].size(); j++) {
                std::cerr << " " << expectations[i][j];
            }
            std::cerr << "\n";

            return 0;
        }

        for (int j = 0; j < expectations[i].size(); j++) {
            if (result[j] != expectations[i][j]) {
                std::cerr << "FAIL: bad result for " << input[i];

                std::cerr << ": got ";
                for (int j = 0; j < result.size(); j++) {
                    std::cerr << " " << result[j];
                }

                std::cerr << " expected ";
                for (int j = 0; j < expectations[i].size(); j++) {
                    std::cerr << " " << expectations[i][j];
                }
                std::cerr << "\n";

                return 0;
            }
        }
    }

    std::cout << "PASS";

    return 0;
}