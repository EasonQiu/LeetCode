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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if ( inorder.size() == 0) return NULL;
        return build( inorder, postorder, 0,  inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* build(const vector<int>& inorder, const vector<int>& postorder,
                    int leftIn, int rightIn, int leftPost, int rightPost){
        if (leftPost == rightPost){
            return  new TreeNode(postorder[rightPost]);
        }else {
            TreeNode* node = new TreeNode(postorder[rightPost]);
            int pos = leftIn;
            while (inorder[pos] != postorder[rightPost])  ++pos;
            if (leftIn < pos)
                node->left = build(inorder, postorder, leftIn, pos-1, leftPost, leftPost+pos-leftIn-1);
            if (pos < rightIn)
                node->right = build(inorder, postorder, pos+1, rightIn, leftPost+pos-leftIn, rightPost-1);
            return node;
        }
    }
};

int main() {
    TreeNode *node;
    int pre[] = {1,2,4,5,3}, in[] = {4,2,5,1,3}, post[] = {4,5,2,3,1};
    vector<int> preorder(pre,pre+5), inorder(in,in+5), postorder(post,post+5);
    
    Solution s;
    node = s.buildTree(inorder, postorder);
    
    return 0;
}