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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        // calculate the max height of tree
        int maxHeight = 1;
        TreeNode* tmp = root;
        while (tmp->left) {
            tmp = tmp->left;  ++maxHeight;
        }
        return count(root, 1, maxHeight);
    }
    
    int count(TreeNode* node, int height, const int &maxHeight){
        if (!node) return 0;
        // calculate the height of left subtree
        int h = height;
        if (TreeNode* tmp = node->left) {
            ++h;
            while (tmp && tmp->right) {
                tmp = tmp->right;  ++h;
            }
        }
        // calculate the number of nodes
        if (h == maxHeight){ // a perfect left subtree
            return (int)pow(2,maxHeight - height) - 1 + count(node->right, height+1, maxHeight) + 1;
        }else { // not a perfect left subtree
            return count(node->left, height+1, maxHeight) + (int)pow(2,maxHeight - height - 1) - 1 + 1;
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
//    node2->right = node5;
    
    Solution s;
    cout << s.countNodes(node1);
    
    return 0;
}