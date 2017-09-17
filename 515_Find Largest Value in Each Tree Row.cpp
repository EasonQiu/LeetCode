// You need to find the largest value in each row of a binary tree.

// Example:
// Input: 
//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 
// Output: [1, 3, 9]

class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
  	if (!root)  return vector<int>();
  	vector<int> ans;
  	queue<TreeNode*> queue;
  	TreeNode *node;
  	int size, row_max;
  	queue.push(root);
  	while (!queue.empty()) {
  		row_max = INT_MIN;
  		size = queue.size();
  		for (int i = 0; i < size; ++i) {
  			node = queue.front();  queue.pop();
  			row_max = max(row_max, node->val);
  			if (node->left)  queue.push(node->left);
  			if (node->right)  queue.push(node->right);
  		}
  		ans.push_back(row_max);
  	}
  	return ans;
  }
};