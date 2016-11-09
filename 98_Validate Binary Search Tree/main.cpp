#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        // check if the left subtree is validated
        if (!validate(node->left, prev)) return false;
        // check if the current node is validated
        if (prev != NULL && prev->val >= node->val) return false;
        // in-order update prev
        prev = node;
        // check if the left subtree is validated
        return validate(node->right, prev);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    std::cout << s.isValidBST(node2) << std::endl;
    
    return 0;
}