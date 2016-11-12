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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder,
                    int leftPre, int rightPre, int leftIn, int rightIn){
        if (leftPre == rightPre){
            return  new TreeNode(preorder[leftPre]);
        }else {
            TreeNode* node = new TreeNode(preorder[leftPre]);
            int pos = leftIn;
            while (inorder[pos] != preorder[leftPre])  ++pos;
            if (leftIn < pos)
                node->left = build(preorder, inorder, leftPre+1, leftPre+pos-leftIn, leftIn, pos-1);
            if (pos < rightIn)
                node->right = build(preorder, inorder, leftPre+pos-leftIn+1, rightPre, pos+1, rightIn);
            return node;
        }
    }
};

int main() {
    TreeNode *node;
    int pre[] = {1,2,4,5,3}, in[] = {4,2,5,1,3}, post[] = {4,5,2,3,1};
    vector<int> preorder(pre,pre+5), inorder(in,in+5), postorder(post,post+5);
    
    Solution s;
    node = s.buildTree(preorder, inorder);
    
    return 0;
}