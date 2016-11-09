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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p != nullptr  && q != nullptr)
            return ( p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
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
    node2->left = node1;  node1->right = node3;
    
    Solution s;
    cout << s.isSameTree(node2, node3);
    
    
    return 0;
}