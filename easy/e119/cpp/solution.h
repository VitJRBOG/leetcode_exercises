#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return std::vector<int>{1};
        }

        if (rowIndex == 1) {
            return std::vector<int>{1, 1};
        }

        std::vector<int> result(rowIndex + 1);
        result[0] = 1;
        result[1] = 2;
        result[2] = 1;

        rowIndex -= 2;

        while (rowIndex > 0) {
            int32_t tmp1 = result[0];
            int32_t tmp2 = result[1];
            for (int8_t i = 1;; i++) {
                if (i > 1) {
                    if (i % 2 == 0) {
                        tmp1 = result[i];
                    } else {
                        tmp2 = result[i];
                    }
                }

                if (i > 1 and tmp1 <= 1 and tmp2 <= 1) {
                    result[i] = 1;
                    break;
                }

                result[i] = tmp1 + tmp2;
            }

            rowIndex--;
        }

        return result;
    }
};