class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
  	vector<int> ans;
  	stack<TreeNode*> stack; // store nodes waiting to output
  	TreeNode *node = root, *last_node = NULL; // node points to unprocessed node
  	while (node || !stack.empty()) {
  		if (node) {
  			stack.push(node);
  			node = node->left;
  		} else {
  			TreeNode *top_node = stack.top();
  			if (top_node->right && top_node->right != last_node) {
  				node = top_node->right;
  			} else {
  				ans.push_back(top_node->val);
  				last_node = top_node;
  				stack.pop();
  			}
  		}
  	}
  	return ans;
  }
};


// use deque, every time push_front
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
  	deque<int> ans;
  	stack<TreeNode*> stack;
  	TreeNode *node = root;
  	while (node || !stack.empty()) {
  		if (node) {
  			stack.push(node);
  			ans.push_front(node->val);
  			node = node->right;
  		} else {
  			node = stack.top();  stack.pop();
  			node = node->left;
  		}
  	}
  	return vector<int>(ans.begin(), ans.end());
  }
};