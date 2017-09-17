// Given the root of a binary tree, then value v and depth d, you need to add a row of 
// nodes with value v at the given depth d. The root node is at depth 1.

// The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in 
// depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. 
// And N's original left subtree should be the left subtree of the new left subtree root, 
// its original right subtree should be the right subtree of the new right subtree root. 
// If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v 
// as the new root of the whole original tree, and the original tree is the new root's left 
// subtree.

// Example 1:
// Input: 
// A binary tree as following:
//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
// v = 1
// d = 2

// Output: 
//        4
//       / \
//      1   1
//     /     \
//    2       6
//   / \     / 
//  3   1   5   


class Solution {
public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode *p = new TreeNode(v);
      p->left = root;
      return p;
    }
    queue<TreeNode*> queue;
    TreeNode *node, *temp;
    int size;
    // find the nodes of level d - 1
    queue.push(root);
    for (int k = 2; k < d; ++k) {
      size = queue.size();
      for (int i = 0; i < size; ++i) {
        node = queue.front();  queue.pop();
        if (node->left)   queue.push(node->left);
        if (node->right)  queue.push(node->right);
      }
    }
    // add one level after level d - 1
    size = queue.size();
    TreeNode *new_node;
    for (int i = 0; i < size; ++i) {
      node = queue.front();  queue.pop();
      new_node = new TreeNode(v);
      new_node->left = node->left;  node->left = new_node;
      new_node = new TreeNode(v);
      new_node->right = node->right;  node->right = new_node;
    }
    return root;
  }
};