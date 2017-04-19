#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode* parent = NULL;
        return dfs(root, parent);
    }
    
    int dfs(TreeNode* node, TreeNode* parent){
        if (!node)  return 0;
        if (!node->left && !node->right){ // go the leaf nodes
            if (parent && node == parent->left)  return node->val;
            else  return 0;
        }
        return dfs(node->left, node) + dfs(node->right, node);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    cout << s.sumOfLeftLeaves(node2);
    
    
    return 0;
}