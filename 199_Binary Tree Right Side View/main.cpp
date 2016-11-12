#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // non-recursion version, bfs
    vector<int> rightSideView(TreeNode* root){
        vector<int> result;
        queue<TreeNode*> nodes;
        vector<int> values;
        TreeNode* curr;
        
        if (!root) return result;
        nodes.push(root);
        while (nodes.size() != 0){
            values.clear();
            unsigned long size = nodes.size(), i = 0;
            for (; i < size; ++i){
                curr = nodes.front();  nodes.pop();
                values.push_back(curr->val);
                if (i == size-1) result.push_back(curr->val);
                if (curr->left)  nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
            }
        }

        return result;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    node1->right = node2;
    node1->left = node4;
    node2->left = node3;
    
    Solution s;
    s.rightSideView(node1);
    
    return 0;
}