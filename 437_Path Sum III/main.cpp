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
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        vector<int> sums;
        int num = 0;
        dfs(root, sums, sum, num);
        return num;
    }
    
    void dfs(TreeNode *p, vector<int> &sums, const int &sum, int &num) {
        sums.push_back(0);
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] += p->val;
            if (sums[i] == sum) ++num;
        }
        if (p->left)  dfs(p->left, sums, sum, num);
        if (p->right) dfs(p->right, sums, sum, num);
        
        sums.pop_back();
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] -= p->val;
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node2->left = node3;
//    node3->left = node4;
//    node4->left = node5;
    
    Solution s;
    cout << s.pathSum(node1, 3);
    
    
    return 0;
}