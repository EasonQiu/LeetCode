// Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

// Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

// Example 1:
// Input:
//         1
//        / \
//       2   3
// Output: 2
// Explanation: The longest consecutive path is [1, 2] or [2, 1].
// Example 2:
// Input:
//         2
//        / \
//       1   3
// Output: 3
// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
// Note: All the values of tree nodes are in the range of [-1e7, 1e7].



class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int max_len = 0;
        longestPath(root, max_len);
        return max_len;
    }
    
    // return value is <longest in increasing order, longest in decreasing order>
    pair<int, int> longestPath(TreeNode* node, int& max_len) {
        if (!node)  return make_pair(0, 0);
        int max_asec = 1, max_desc = 1;
        if (node->left) {
            pair<int, int> left_len = longestPath(node->left, max_len);
            if (node->left->val + 1 == node->val)  max_desc = left_len.second + 1;
            if (node->left->val - 1 == node->val)  max_asec = left_len.first + 1;
        }
        if (node->right) {
            pair<int, int> right_len = longestPath(node->right, max_len);
            if (node->right->val + 1 == node->val)  max_desc = max(max_desc, right_len.second + 1);
            if (node->right->val - 1 == node->val)  max_asec = max(max_asec, right_len.first + 1);
        }
        max_len = max(max_len, max_asec + max_desc - 1);
        return make_pair(max_asec, max_desc);
    }
};