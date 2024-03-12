#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::map<char, int32_t> frequency;

        for (int32_t i = 0; i < s.size(); i++) {
            frequency[s[i]]++;
        }

        s = "";

        while (true) {
            int32_t freq = 0;
            char mostFrequent = '\0';
            for (auto it = frequency.begin(); it != frequency.end(); it++) {
                if (mostFrequent == '\0') {
                    mostFrequent = it->first;
                    freq = it->second;
                    continue;
                }

                if (freq < it->second) {
                    mostFrequent = it->first;
                    freq = it->second;
                }
            }

            if (frequency.size() == 0) {
                break;
            }

            for (; 0 < frequency[mostFrequent]; frequency[mostFrequent]--) {
                s += mostFrequent;
            }

            frequency.erase(mostFrequent);
        }

        return s;
    }
};