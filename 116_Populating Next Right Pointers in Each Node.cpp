#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> nodes;
        vector<int> values;
        TreeLinkNode* curr;
    
        nodes.push(root);
        while (nodes.size() != 0){
            values.clear();
            unsigned long size = nodes.size(), i = 0;
            for (; i < size; ++i){
                curr = nodes.front();  nodes.pop();
                values.push_back(curr->val);
                
                if (i == size-1) curr->next = NULL;
                else curr->next = nodes.front();
                
                if (curr->left)  nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
            }
        }
        return;
    }
};

int main() {
    TreeLinkNode *node1 = new TreeLinkNode(1);
    TreeLinkNode *node2 = new TreeLinkNode(2);
    TreeLinkNode *node3 = new TreeLinkNode(3);
    TreeLinkNode *node4 = new TreeLinkNode(4);
    TreeLinkNode *node5 = new TreeLinkNode(5);
    TreeLinkNode *node6 = new TreeLinkNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    
    Solution s;
    s.connect(node1);
    
    return 0;
}