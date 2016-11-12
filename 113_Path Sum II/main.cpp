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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (!root) return result;
        vector<int> path;
        dfs(root, 0, sum, path, result);
        return result;
    }
    
    void dfs(TreeNode *p, int currsum, const int &sum, vector<int> &path, vector<vector<int> > &result) {
        currsum += p->val;  path.push_back(p->val);
        if (!p->left && !p->right) { // go to the leaf nodes
            if (currsum == sum) result.push_back(path);
        }
        if (p->left)  dfs(p->left,  currsum, sum, path, result);
        if (p->right) dfs(p->right, currsum, sum, path, result);
        currsum -= p->val;  path.pop_back();
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;
    node2->right = node3;
    
    Solution s;
    s.pathSum(node2, 5);
    
    return 0;
}