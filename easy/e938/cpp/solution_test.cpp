#include "solution.h"

#include <cassert>
#include <iostream>
#include <vector>

TreeNode* makeATree(TreeNode* pTN, std::vector<int> items, int* pBranchID) {
    if (items.size() <= *pBranchID) {
        return pTN;
    }

    if (pTN == nullptr) {
        if (items[*pBranchID] != -1) {
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
    std::vector<std::vector<int>> input1 = {{10, 5, 15, 3, 7, -1, 18}, {10, 5, 15, 3, 7, 13, 18, 1, -1, 6}};
    std::vector<int> input2 = {7, 6};
    std::vector<int> input3 = {15, 10};

    std::vector<int> expectations = {32, 23};

    if (input1.size() != input2.size() || input2.size() != input3.size() ||
        input3.size() != expectations.size() || expectations.size() != input1.size()) {
        std::cerr << "test is invalid";
        return 0;
    }

    Solution s;
    for (int i = 0; i < input1.size(); i++) {
        assert(1 <= input2[i] and input2[i] <= pow(10, 5));
        assert(1 <= input3[i] and input3[i] <= pow(10, 5));

        TreeNode tn = TreeNode(input1[i][0]);
        int temp = 1;
        TreeNode* pTN = makeATree(&tn, input1[i], &temp);

        int result = s.rangeSumBST(pTN, input2[i], input3[i]);

        if (result != expectations[i]) {
            std::cerr << "FAIL: bad result for [";

            for (int j = 0; j < input1[i].size(); j++) {
                if (j > 0) {
                    std::cerr << ", ";
                }
                if (input1[i][j] == -1) {
                    std::cerr << "null";
                } else {
                    std::cerr << input1[i][j];
                }
            }

            std::cerr << "], " << input2[i] << ", and " << input3[i];

            std::cerr << ": got " << result;
            std::cerr << " expected " << expectations[i] << std::endl;

            return 0;
        }
    }

    std::cout << "PASS";

    return 0;
}