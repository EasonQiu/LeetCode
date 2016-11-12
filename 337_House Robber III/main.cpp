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
    int rob(TreeNode* root) {
        return rob_help(root).first;
    }
    
    // I maintain result in a pair, first part indicates best benefit no matter whether includes himself,
    // and second part indicates the one without including himself.
    // So root->val + left.second + right.second means includes himself but skip all his children.
    pair<int, int> rob_help(TreeNode *root) {
        pair<int, int> result(0, 0);
        if (root != NULL) {
            pair<int, int> left = rob_help(root->left);
            pair<int, int> right = rob_help(root->right);
            result.second = left.first + right.first;
            result.first = max(root->val + left.second + right.second, result.second);
        }
        return result;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(3);
    node1->left = node2;
    node2->left = node3;
    node3->left = node4;
    
    Solution s;
    cout << s.rob(node1);
    
    return 0;
}