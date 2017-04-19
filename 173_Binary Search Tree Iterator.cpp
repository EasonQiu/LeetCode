#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        create(root);
        currIndex = -1;  size = sortedNodes.size();
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return currIndex + 1 < size;
    }
    
    /** @return the next smallest number */
    int next() {
        return (sortedNodes[++currIndex])->val;
    }

private:
    void create(TreeNode *p){
        if (p){
            create(p->left);
            sortedNodes.push_back(p);
            create(p->right);
        }
    }
    
    int currIndex, size;
    vector<TreeNode*> sortedNodes;
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node2->left = node1;  node2->right = node3;
    
    BSTIterator i = BSTIterator(node2);
    while (i.hasNext()) cout << i.next();
    
    
    return 0;
}