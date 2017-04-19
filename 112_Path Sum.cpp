#include <iostream>
#include <queue>
#include <string>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        bool flag = false;
        dfs(root, 0, sum, flag);
        return flag;
    }
    
    void dfs(TreeNode* p, int currsum, const int& sum, bool &flag){
        if (!flag){
            currsum += p->val;
            if (!p->left && !p->right){ // go to the leaf nodes
                if (currsum == sum) flag = true;
                return;
            }
            if (p->left)   dfs(p->left, currsum, sum, flag);
            if (p->right)  dfs(p->right, currsum, sum, flag);
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    cout << s.hasPathSum(node2, 4);
    
    
    return 0;
}