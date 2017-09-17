// Given two non-empty binary trees s and t, check whether tree t has exactly the same 
// structure and node values with a subtree of s. A subtree of s is a tree consists of a node 
// in s and all of this node's descendants. The tree s could also be considered as a subtree of 
// itself.

// Example 1:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
// Given tree t:
//    4 
//   / \
//  1   2
// Return true, because t has the same structure and node values with a subtree of s.

// Example 2:
// Given tree s:
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// Given tree t:
//    4
//   / \
//  1   2
// Return false.

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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    // base case
    if (!s && !t)  return true;
    if (!s || !t)  return false;
    // check if tree t is the same as tree s
    if (isSame(s, t))  return true;
    // check if tree t is in the child subtrees
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool isSame(TreeNode *s, TreeNode *t) {
    if (!s && !t)  return true;
    if (!s || !t)  return false;
    if (s->val != t->val)  return false;
    return isSame(s->left, t->left) && isSame(s->right, t->right);
  }
};