#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

TreeNode* makeATree(TreeNode* pTN, std::vector<int> items, int* pBranchID) {
    if (items.size() <= *pBranchID) {
        return pTN;
    }

    if (pTN == nullptr) {
        if (items[*pBranchID] != -32768) {
            pTN = new TreeNode;
            pTN->val = items[*pBranchID];
        }
        (*pBranchID)++;
        return pTN;
    }

    pTN->left = makeATree(pTN->left, items, pBranchID);
    pTN->right = makeATree(pTN->right, items, pBranchID);

    if (pTN->val == items[0]) {
        while (*pBranchID < items.size()) {
            pTN->left = makeATree(pTN->left, items, pBranchID);
            pTN->right = makeATree(pTN->right, items, pBranchID);
        }
    }
    return pTN;
}

int main() {
    std::vector<std::vector<int>> input1 = {{1, 2, 3}, {1, 2}, {1, 2, 1}};
    std::vector<std::vector<int>> input2 = {{1, 2, 3}, {1, -32768, 2}, {1, 1, 2}};

    std::vector<bool> expectations = {true, false, false};

    if (input1.size() != input2.size() || input2.size() != expectations.size() ||
        expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        int n = 0;
        for (int j = 0; j < input1[i].size(); j++) {
            if (input1[i][j] != -32768) {
                n++;
                assert(-pow(10, 4) <= input1[i][j] && input1[i][j] <= pow(10, 4));
            }
        }
        assert(0 <= n && n <= 100);

        n = 0;
        for (int j = 0; j < input2[i].size(); j++) {
            if (input2[i][j] != -32768) {
                n++;
                assert(-pow(10, 4) <= input2[i][j] && input2[i][j] <= pow(10, 4));
            }
        }
        assert(0 <= n && n <= 100);

        TreeNode tn1 = TreeNode(input1[i][0]);
        int temp = 1;
        TreeNode* pTN1 = makeATree(&tn1, input1[i], &temp);

        TreeNode tn2 = TreeNode(input2[i][0]);
        temp = 1;
        TreeNode* pTN2 = makeATree(&tn2, input2[i], &temp);

        bool result = s.isSameTree(pTN1, pTN2);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < input1[i].size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                if (input1[i][j] == -32768) {
                    std::cerr << "null";
                } else {
                    std::cerr << input1[i][j];
                }
            }

            std::cerr << "] and [";

            for (int j = 0; j < input2.size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                if (input2[i][j] == -32768) {
                    std::cerr << "null";
                } else {
                    std::cerr << input2[i][j];
                }
            }

            std::cerr << "]: got " << result;
            std::cerr << " expected " << expectations[i] << "\n";

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}