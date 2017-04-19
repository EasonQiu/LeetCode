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
    // recursion version, dfs
    int maxDepth(TreeNode* root) {
        if (root == NULL)  return 0;
        return  max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void dfs(vector<vector<int> >& result, TreeNode* p, int level, const int& depth) {
        if (p){
            result[level].push_back(p->val);
            dfs(result, p->left, level + 1, depth);
            dfs(result, p->right, level + 1, depth);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)  {
        int depth = maxDepth(root);
        vector<vector<int> > result(depth);
        dfs(result, root, 0, depth);
        
        int left, right, tmp;
        for (int i = 1; i < result.size(); i = i + 2){
            left = 0;  right = result[i].size()-1;
            while (left < right){
                tmp = result[i][left]; result[i][left] = result[i][right];  result[i][right] = tmp;
                ++left;  --right;
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
    node1->right = node3;
    node1->left = node2;
    node2->left = node4;
    
    Solution s;
    s.zigzagLevelOrder(node1);
    
    return 0;
}