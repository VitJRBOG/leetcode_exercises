#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {
    std::vector<std::string> input1 = { "tree", "cccaaa", "Aabb" };

    std::vector<std::string> expectations = { "eert" , "aaaccc", "bbAa" };

    if (input1.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(1 <= input1[i].size() && input1[i].size() <= 5 * pow(10, 5));

        std::string result = s.frequencySort(input1[i]);

        std::string lowercasedResult = result;
        std::transform(lowercasedResult.begin(), lowercasedResult.end(), lowercasedResult.begin(), asciitolower);
        std::string lowercasedExpectation = expectations[i];
        std::transform(lowercasedExpectation.begin(), lowercasedExpectation.end(), lowercasedExpectation.begin(), asciitolower);

        if (lowercasedResult != lowercasedExpectation) {
            std::cerr << "FAIL: bad result for \"" << input1[i];
            std::cerr << "\": got \"" << result;
            std::cerr << "\" expected \"" << expectations[i];
            std::cerr << "\"" << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}