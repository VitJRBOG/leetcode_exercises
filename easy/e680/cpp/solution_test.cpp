#include "solution.h"

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> input = {"aba",
                                      "abca",
                                      "abc",
                                      "abccqba",
                                      "abccqcba",
                                      "abccqlba",
                                      "deeee",
                                      "gmlueuppuclmg",
                                      "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpf"
                                      "dhooxfuupuculmgmqfvnbgtapekouga",
                                      "ebcbbececabbacecbbcbe"};

    std::vector<bool> expectations = {true, true, false, true, true, false, true, false, true, true};

    if (input.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input.size(); i++) {
        assert(1 <= input[i].size() and input[i].size() <= pow(10, 5));

        std::vector<int> origInput(input[i].size());

        for (int k = 0; k < origInput.size(); k++) {
            origInput[k] = input[i][k];
        }

        bool result = s.validPalindrome(input[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for \"" << input[i];

            std::cerr << "\": got " << result;
            std::cerr << " expected " << expectations[i] << "\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}