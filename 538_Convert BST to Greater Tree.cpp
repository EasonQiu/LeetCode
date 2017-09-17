// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of 
// the original BST is changed to the original key plus sum of all keys greater than the 
// original key in BST.

// Example:

// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13

// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13


class Solution {
public:
  TreeNode* convertBST(TreeNode* root) {
  	if (!root)  return NULL;
  	int greater_sum = 0;
  	helper(root, greater_sum);
  	return root;
  }

  void helper(TreeNode *root, int &greater_sum) {
  	if (!root)  return;
  	helper(root->right, greater_sum);
  	root->val += greater_sum;  
  	greater_sum = root->val;
  	helper(root->left, greater_sum);
  }
};