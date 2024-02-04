#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    std::vector<std::string> stringMatching(std::vector<std::string>& words) {
        uint8_t len = words.size();

        if (len == 1) {
            return words;
        }

        for (uint8_t i = 1; i < len; i++) {
            uint8_t n = i;
            while (n > 0 && words[n].size() < words[n - 1].size()) {
                std::string tmp = words[n - 1];
                words[n - 1] = words[n];
                words[n] = tmp;
                n--;
            }
        }

        std::vector<std::string> result;

        for (uint8_t i = 0; i < len; i++) {
            uint8_t n = i + 1;
            while (n < len) {
                if (words[n].find(words[i]) != std::string::npos) {
                    result.push_back(words[i]);
                    break;
                }
                n++;
            }
        }

        return result;
    }
};