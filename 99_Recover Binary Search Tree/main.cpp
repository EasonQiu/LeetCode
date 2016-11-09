#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pos1 = NULL, *pos2 = NULL, *prev = NULL, *pos1Prev = NULL;
        int tmp;
        
        search(root, prev, pos1, pos1Prev, pos2);
        if (pos2){ // two nodes are not next to each other
            tmp = pos1Prev->val;  pos1Prev->val = pos2->val;  pos2->val = tmp;
        }else{ // two nodes are next to each other
            tmp = pos1->val;  pos1->val = pos1Prev->val;  pos1Prev->val = tmp;
        }
    }
    
    void search(TreeNode* p, TreeNode* &prev, TreeNode* &pos1, TreeNode* &pos1Prev, TreeNode* &pos2){
        if (p){
            // search left subtree
            search(p->left, prev, pos1, pos1Prev, pos2);
            // check the current node
            if (prev != NULL && prev->val >= p->val){
                if (!pos1){
                    pos1 = p;  pos1Prev = prev;
                }else if (!pos2){
                    pos2 = p;  return;
                }
            }
            prev = p;
            // search right subtree
            search(p->right, prev, pos1, pos1Prev, pos2);
        }
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node3;
    node2->right = node1;
    
    Solution s;
    s.recoverTree(node2);
    
    return 0;
}