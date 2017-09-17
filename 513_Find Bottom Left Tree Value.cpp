// Given a binary tree, find the leftmost value in the last row of the tree.

// Example 1:
// Input:
//     2
//    / \
//   1   3
// Output:
// 1

// Example 2: 
// Input:
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
// Output:
// 7

// Note: You may assume the tree (i.e., the given root node) is not NULL.


class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> queue;
    int leftmost;
    TreeNode *node;
    queue.push(root);
    while (!queue.empty()) {
      leftmost = queue.front()->val;
      int size = queue.size();
      for (int i = 0; i < size; ++i) {
        node = queue.front();  queue.pop();
        if (node->left)  queue.push(node->left);
        if (node->right)  queue.push(node->right);
      }
    }
    return leftmost;
  }
};
