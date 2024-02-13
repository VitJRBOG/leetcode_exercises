#include <iostream>
#include <string>
#include <vector>

class Solution {
   public:
    int minDistance(std::string word1, std::string word2) {
        int16_t lenWord1 = word1.size();
        int16_t lenWord2 = word2.size();

        if (lenWord1 == 0 && lenWord2 == 0) {
            return 0;
        } else if (lenWord1 == 0 && lenWord2 != 0) {
            return lenWord2;
        } else if (lenWord1 != 0 && lenWord2 == 0) {
            return lenWord1;
        }

        std::vector<int16_t> row(lenWord1);

        for (int16_t i = 0; i < lenWord1; i++) {
            row[i] = i + 1;
        }

        int16_t x = -1;
        int16_t y = -1;
        int16_t z = -1;

        for (int16_t j = 0; j < lenWord2; j++) {
            z = j;
            x = row[0];
            y = j + 1;

            for (int16_t i = 0; i < lenWord1; i++) {
                row[i] = z;
                if (word2[j] != word1[i]) {
                    row[i]++;
                }

                if ((y + 1) < row[i]) {
                    row[i] = y + 1;
                }

                if ((x + 1) < row[i]) {
                    row[i] = x + 1;
                }

                if (i < (lenWord1 - 1)) {
                    z = x;
                    x = row[i + 1];
                    y = row[i];
                }
            }
        }

        return row[lenWord1 - 1];
    }
};