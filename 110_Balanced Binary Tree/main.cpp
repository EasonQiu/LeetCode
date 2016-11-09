#include <iostream>
#include <vector>
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        if (!isBalanced(root->left)) return false;
        return isBalanced(root->right);
    }
    
    int depth(TreeNode* root){
        if (!root)  return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1->right = node2;
    node1->left = node3;
    
    Solution s;
    cout << s.isBalanced(node1);
    
    return 0;
}