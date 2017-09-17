// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most 
// frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
// For example:
// Given BST [1,null,2,2],
//    1
//     \
//      2
//     /
//    2
// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack 
// space incurred due to recursion does not count).


class Solution {
public:
  vector<int> findMode(TreeNode* root) {
  	vector<int> ans;
  	if (!root)  return ans;
  	// inorder traversal
  	int pre_val = INT_MIN, pre_count = 0, max_count = 1;
  	stack<TreeNode*> stack; // denote nodes  waiting to be visited
  	TreeNode *node = root; // denote unvisited nodes
  	while (node || !stack.empty()) {
  		if (node) {
  			stack.push(node);
  			node = node->left;
  		} else {
  			node = stack.top();  stack.pop();
  			// operate on the current node
  			if (node->val != pre_val) {
  				if (pre_count > max_count) {
  					max_count = pre_count;
  					ans.clear();  ans.push_back(pre_val);
  				} else if (pre_count == max_count) {
  					ans.push_back(pre_val);
  				}
  				pre_val = node->val;  pre_count = 1;
  			} else {
  				pre_count += 1;
  			}
  			// move to the right subtree
  			node = node->right;
  		}
  	}
  	// solve the last case
  	if (pre_count > max_count) {
  		ans.clear();  ans.push_back(pre_val);
  	} else if (pre_count == max_count) {
  		ans.push_back(pre_val);
  	}
  	// final result
  	return ans;
  }
};