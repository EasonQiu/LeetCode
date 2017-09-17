// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        int min_diff = INT_MAX;
        traverse(root, prev, min_diff);
        return min_diff;
    }
    
    void traverse(TreeNode* curr, TreeNode* &prev, int &min_diff) {
        if (!curr)  return;
        traverse(curr->left, prev, min_diff);
        if (prev)  min_diff = min(min_diff, curr->val - prev->val);
        prev = curr;
        traverse(curr->right, prev, min_diff);
    }
};