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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    void traverse(TreeNode *root, vector<int> &result){
        if (root) {
            traverse(root->left, result);
            result.push_back(root->val);
            traverse(root->right, result);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}