#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int depth = treeDepth(root), currDepth = 0;;
        vector<int> answer(depth);
        if (!root)  return answer;
        queue<TreeNode*> levelNodes;  levelNodes.push(root);
        while (!levelNodes.empty()) {
        	answer[currDepth++] = levelNodes.back()->val;
        	int size = levelNodes.size();
        	for (int i = 0; i < size; ++i) {
        		TreeNode *temp = levelNodes.front();
        		levelNodes.pop();
        		if (temp->left)   levelNodes.push(temp->left);
        		if (temp->right)  levelNodes.push(temp->right);
        	}
        }
        return answer;
    }

private:
	int treeDepth(TreeNode *node) {
		if (!node)  return 0;
		else return max(treeDepth(node->left) + 1, treeDepth(node->right) + 1);
	}
};

int main() {
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);

	n1->left = n2;  n1->right = n3;  n2->right = n5;  n3->right = n4;
	Solution s;
	vector<int> answer = s.rightSideView(n1);

	for (int num : answer) {
		cout << num << " ";
	}
	return 0;
}