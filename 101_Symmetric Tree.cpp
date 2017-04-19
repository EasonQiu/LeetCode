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
    bool isSymmetric(TreeNode* root) {
        if ((!root) || (!root->left && !root->right))  return true;
        else return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (p != nullptr  && q != nullptr)
            return ( p->val==q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left) );
        else if (p == nullptr  && q == nullptr)
            return true;
        else
            return false;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    cout << s.isSymmetric(node2);
    
    
    return 0;
}