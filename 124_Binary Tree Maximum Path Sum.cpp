#include <iostream>
#include <map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // beats 84.72%
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    // return value is the maximum path sum of this node
    int dfs(TreeNode* p, int& maxSum) {
    	if (!p)  return 0;
    	int leftMax  = max(dfs(p->left,  maxSum), 0);
    	int rightMax = max(dfs(p->right, maxSum), 0);
    	maxSum = max(maxSum, leftMax + rightMax + p->val);
    	return max(leftMax, rightMax) + p->val;
    }
};

int main() {
	TreeNode *n1 = new TreeNode(-1), *n2 = new TreeNode(2), *n3 = new TreeNode(3);
	n2->left = n1;  
	// n2->right = n3;

	Solution s;
	cout << s.maxPathSum(n2) << endl;

	return 0;
}