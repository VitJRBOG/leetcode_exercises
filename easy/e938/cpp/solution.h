#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        return ((root->left != nullptr ? rangeSumBST(root->left, low, high) : 0) +
                (root->right != nullptr ? rangeSumBST(root->right, low, high) : 0)) +
               ((low <= root->val && root->val <= high) ? root->val : 0);
    }
};