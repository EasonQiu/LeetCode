#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* node;
        vector<TreeNode*> stack;
        vector<int> result;
        
        if (!root) return result;
        stack.push_back(root);
        while (!stack.empty()){
            node = stack.back();
            result.push_back(node->val);
            stack.pop_back();
            
            if (node->right) stack.push_back(node->right);
            if (node->left)  stack.push_back(node->left);
        }
        
        return result;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1->right = node2;
    node2->left = node3;
    
    Solution s;
    s.preorderTraversal(node1);
    
    return 0;
}