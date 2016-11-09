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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)  return vector<string>();
        vector<vector<TreeNode*> > allPaths;
        vector<TreeNode*> path;
        dfs(root, path, allPaths);
        
        vector<string> result;
        for (int i = 0; i < allPaths.size(); ++i){
            string s = to_string(allPaths[i][0]->val);
            if (allPaths[i].size() > 1){
                for (int j = 1; j < allPaths[i].size(); ++j)
                    s += "->" + to_string(allPaths[i][j]->val);
            }
            result.push_back(s);
        }
        return result;
    }
    
    void dfs(TreeNode* p, vector<TreeNode*> &path, vector<vector<TreeNode*> > &allPaths){
        path.push_back(p);
        if (!p->left && !p->right){ // go to the leaf nodes
            allPaths.push_back(path);
            path.pop_back();  return;
        }
        if (p->left)   dfs(p->left, path, allPaths);
        if (p->right)  dfs(p->right, path, allPaths);
        path.pop_back();
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    s.binaryTreePaths(node2);
    
    
    return 0;
}