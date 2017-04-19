#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root || k <= 0) return INT_MIN;
        stack<TreeNode*> my_stack;
        while(root || !my_stack.empty()){
            if(root){
                my_stack.push(root);
                root = root->left;
            } else {
                root = my_stack.top();  my_stack.pop();
                if(--k == 0) return root->val;
                root = root->right;
            }
        }
        return INT_MIN;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    cout << s.kthSmallest(node2, 2);
    
    return 0;
}