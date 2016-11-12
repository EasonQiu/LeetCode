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
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int currSum, int &sum){
        currSum = currSum * 10 + node->val;
        if (!node->left && !node->right){
            sum += currSum;  return;
        }
        if (node->left)  dfs(node->left, currSum, sum);
        if (node->right) dfs(node->right, currSum, sum);
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
    cout << s.sumNumbers(node1);
    
    return 0;
}