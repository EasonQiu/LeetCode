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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root)  return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            ans.push_back(vector<int>());
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                ans.back().push_back(node->val);
                if (node->left)  que.push(node->left);
                if (node->right)  que.push(node->right);
            }
        }
        return ans;
    }
};

class Solution {
public:
    // recursion version, dfs
    int maxDepth(TreeNode* root) {
        if (root == NULL)  return 0;
        return  max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    void dfs(vector<vector<int> >& result, TreeNode* p, int level) {
        if (p){
            result[level].push_back(p->val);
            dfs(result, p->left, level + 1);
            dfs(result, p->right, level + 1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int depth = maxDepth(root);
        vector<vector<int> > result(depth);
        dfs(result, root, 0);
        return result;
    }
    
    // non-recursion version, bfs
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int> > result;
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
                if (curr->left)  nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
            }
            result.push_back(values);
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
    s.levelOrder(node1);
    
    return 0;
}