#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

ListNode* makeAListNode(ListNode* pLN, std::vector<int> items, int* pItemID) {
    if (items.size() <= (*pItemID)) {
        return pLN;
    }

    if (pLN == nullptr) {
        pLN = new ListNode;
        pLN->val = items[*pItemID];

        (*pItemID)++;
    }

    pLN->next = makeAListNode(pLN->next, items, pItemID);

    return pLN;
}

std::vector<int> listNodeToVector(std::vector<int> items, ListNode* pLN) {
    if (pLN == nullptr) {
        return items;
    }

    items.push_back(pLN->val);
    return listNodeToVector(items, pLN->next);
}

int main() {
    std::vector<std::vector<int>> input1 = { {1, 2, 3, 4, 5},
                                            {1, 2, 3, 4, 5, 6} };

    std::vector<std::vector<int>> expectations = { {3, 4, 5}, {4, 5, 6} };

    if (input1.size() != expectations.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(1 <= input1[i].size() && input1[i].size() <= 100);

        for (int j = 0; j < input1[i].size(); j++) {
            assert(1 <= input1[i][j] && input1[i][j] <= 100);
        }

        ListNode ln = ListNode(input1[i][0]);
        int temp = 1;
        ListNode* pLN = makeAListNode(&ln, input1[i], &temp);

        ListNode* resultLN = s.middleNode(pLN);

        std::vector<int> result;
        result = listNodeToVector(result, resultLN);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < input1[i].size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }

                std::cerr << input1[i][j];
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

            std::cerr << "]" << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}