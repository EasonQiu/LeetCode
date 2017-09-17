// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.


// 找到大于p->val的节点中最小的那个
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        while (root) {
            if (p->val >= root->val) {
                root = root->right;
            } else if (p->val < root->val) {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};

// 这边要注意虽然你找到p之后return了，但其他地方还可能会继续执行修改prev的值
// 所以这种中间临时结束的递归要用return去返回你想要的值
class Solution {  // 对一般的tree通用
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p)  return NULL;
        TreeNode* prev = NULL;
        return postorder(root, prev, p);
    }
    
    // return prev when found p, return NULL if not found
    TreeNode* postorder(TreeNode* curr, TreeNode* &prev, TreeNode* p) {
        if (!curr)  return NULL;
        TreeNode* node = postorder(curr->right, prev, p);
        if (node)  return node;
        if (curr == p)  return prev;
        prev = curr;
        return postorder(curr->left, prev, p);
    }
};