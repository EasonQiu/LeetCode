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
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        queue<TreeNode*> levelNodes;
        TreeNode* currNode;
        int depth = 0;  unsigned long size;
        
        levelNodes.push(root);
        while (levelNodes.size() != 0){
            ++depth;
            size = levelNodes.size();
            for (int i = 0; i < size; ++i){
                currNode = levelNodes.front();  levelNodes.pop();
                if (!currNode->left && !currNode->right)
                    return depth;
                if (currNode->left)  levelNodes.push(currNode->left);
                if (currNode->right)  levelNodes.push(currNode->right);
            }
        }
        return depth;
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node1->right = node3;
    
    Solution s;
    cout << s.minDepth(node2);
    
    
    return 0;
}