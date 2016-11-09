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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max = 0;
        dfs(root, 1, max);
        return max - 1;
    }
    
    void dfs(TreeNode* p, int depth, int &max){
        if (p){
            dfs(p->left, depth + 1, max);
            dfs(p->right, depth + 1, max);
        }else {
            if (depth > max)  max = depth;
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node1->right = node3;
    
    Solution s;
    cout << s.maxDepth(node2);
    
    
    return 0;
}