#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        pair<TreeNode*, TreeNode*> pos = findNode(root, NULL, key); // pair<current, parent>
        if (!pos.first) return root; // do not find the key in the tree
        if (!pos.first->left){ // do not have a left child
            if (!pos.second){ // parent is NULL
                root = root->right;
                delete pos.first;  pos.first = NULL;
                return root;
            }else { // parent is not NULL
                if (pos.first == pos.second->right){ // current is right child of parent
                    pos.second->right = pos.first->right;
                    delete pos.first;  pos.first = NULL;
                    return root;
                }else{ // current is left child of parent
                    pos.second->left = pos.first->right;
                    delete pos.first;  pos.first = NULL;
                    return root;
                }
            }
        }else{ // have a left child
            pair<TreeNode*, TreeNode*> lChild = make_pair(pos.first->left, pos.first); // pair<child, parent>
            while (lChild.first->right){  // find largest node in left subtree
                lChild.second = lChild.first;
                lChild.first = lChild.first->right;
            }
            if (lChild.second == pos.first){ // lChild is exactly the left child of current
                pos.first->val = lChild.first->val;
                pos.first->left = lChild.first->left;
                delete lChild.first;  lChild.first = NULL;
                return root;
            }else { // lChild is not the left child of current
                pos.first->val = lChild.first->val;
                lChild.second->right = lChild.first->left;
                delete lChild.first;  lChild.first = NULL;
                return root;
            }
        }
    }

    pair<TreeNode*, TreeNode*> findNode(TreeNode* p, TreeNode* parent, int key) {
        if (!p) return make_pair(p, parent);
        if (key < p->val)
            return findNode(p->left, p, key);
        else if (key > p->val)
            return findNode(p->right, p, key);
        else
            return make_pair(p, parent);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    Solution s;
    s.deleteNode(node2, 2);
    
    
    return 0;
}