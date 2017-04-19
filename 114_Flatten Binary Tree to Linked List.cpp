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
    void flatten(TreeNode* root) {
        TreeNode *node = root, *tmp;
        while (node){
            if (node->left){
                tmp = node->left;
                while (tmp->right)  { tmp = tmp->right; }
                tmp->right = node->right;
                node->right = node->left;  node->left = NULL;
            }else{
                node = node->right;
            }
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    
    Solution s;
    s.flatten(node1);
    
    return 0;
}