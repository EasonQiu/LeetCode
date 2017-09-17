// Given a binary tree, find the length of the longest consecutive sequence path.

// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        max_len = 0;
        traverse(root);
        return max_len;
    }
    
    int traverse(TreeNode* root) {
        if (!root)  return 0;
        int left_len = traverse(root->left);
        int right_len = traverse(root->right);
        int len = 1;
        if (root->left && root->val + 1 == root->left->val) {
            len = max(len, left_len + 1);
        }
        if (root->right && root->val + 1 == root->right->val) {
            len = max(len, right_len + 1);
        }
        max_len = max(max_len, len);
        return len;
    }

private:
    int max_len;
};