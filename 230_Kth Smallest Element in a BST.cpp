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
        int nums = count(root->left);
        if (nums >= k) {
            return kthSmallest(root->left, k);
        } else if (nums + 1 < k) {
            return kthSmallest(root->right, k - nums - 1);
        }
        return root->val;
    }
    
    int count(TreeNode* node) {
        if (!node)  return 0;
        return 1 + count(node->left) + count(node->right);
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