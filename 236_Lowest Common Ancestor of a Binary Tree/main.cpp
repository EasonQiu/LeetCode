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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2, currPath;
        TreeNode* LCA = NULL;
        findPath(root, p, q, currPath, path1, path2);
    
        unsigned long size = min(path1.size(), path2.size());
        for (int i = 0; i < size; ++i){
            if (path1[i] == path2[i])  LCA = path1[i];
            else break;
        }
        return LCA;
    }
    
    void findPath(TreeNode* root, TreeNode* &p, TreeNode* &q, vector<TreeNode*> &currPath,
                  vector<TreeNode*> &path1, vector<TreeNode*> &path2){
        if (root){
            currPath.push_back(root);
            if (root == p){
                if (path1.empty())  path1 = currPath;
                else if (path2.empty()){
                    path2 = currPath;  return;
                }
            }else if (root == q){
                if (path1.empty())  path1 = currPath;
                else if (path2.empty()){
                    path2 = currPath;  return;;
                }
            }
            
            findPath(root->left, p, q, currPath, path1, path2);
            findPath(root->right, p, q, currPath, path1, path2);
            currPath.pop_back();
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    s.lowestCommonAncestor(node2, node1, node3);
    
    
    return 0;
}