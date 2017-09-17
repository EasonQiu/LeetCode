// Given two binary trees and imagine that when you put one of them to cover the other, 
// some nodes of the two trees are overlapped while the others are not.

// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, 
// then sum node values up as the new value of the merged node. Otherwise, the NOT null node will 
// be used as the node of new tree.

// Example 1:
// Input: 
// 	Tree 1                     Tree 2                  
//           1                         2                             
//          / \                       / \                            
//         3   2                     1   3                        
//        /                           \   \                      
//       5                             4   7                  
// Output: 
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \ 
// 	 5   4   7
// Note: The merging process must start from the root nodes of both trees.


class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  	if (!t2)  return t1;
  	if (!t1)  return t2;
  	TreeNode *node = new TreeNode(t1->val + t2->val);
  	node->left = mergeTrees(t1->left, t2->left);
  	node->right = mergeTrees(t1->right, t2->right);
  	return node;
  }
};


// node t1 will always be valid, if not new TreeNode before enter into this function
class Solution { // in-place of t1
public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  	if (!t2)  return t1;
  	if (!t1)  t1 = new TreeNode(0);
  	t1->val += t2->val;  // current node
  	if (t1->left) { // left substree
  		mergeTrees(t1->left, t2->left);
  	} else if (t2->left) {
  		t1->left = new TreeNode(0);
  		mergeTrees(t1->left, t2->left);
  	}
  	if (t1->right) { // right substree
  		mergeTrees(t1->right, t2->right);
  	} else if (t2->right) {
  		t1->right = new TreeNode(0);
  		mergeTrees(t1->right, t2->right);
  	}
  	return t1;
  }
};