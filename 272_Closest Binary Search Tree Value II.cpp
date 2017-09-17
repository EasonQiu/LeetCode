// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

// Note:
// Given target value is a floating point.
// You may assume k is always valid, that is: k ≤ total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// This is the best solution. Average runtime is O(log(n) + k)
// Building each of the stacks takes O(log(n)) assuming BST is balanced.
// Each call to getNextPred/Succ has an amortized cost of O(1), since every node is pushed and popped at most once.
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans(k);
        // find the pre and succ of target
        initPredecessor(root, target);
        initSuccessor(root, target);
        // take k nodes from two stacks
        int i = 0;
        while (i < k && !pre.empty() && !succ.empty()) {
            if (target - pre.top()->val < succ.top()->val - target) {
                ans[i++] = getPredecessor();
            } else {
                ans[i++] = getSuccessor();
            }
        }
        while (i < k && !pre.empty())   ans[i++] = getPredecessor();
        while (i < k && !succ.empty())  ans[i++] = getSuccessor();        
        return ans;        
    }
    
    int getSuccessor() {
        int val = succ.top()->val;
        TreeNode* node = succ.top()->right;
        succ.pop();
        while (node) {
            succ.push(node);
            node = node->left;
        }
        return val;
    }
    
    int getPredecessor() {
        int val = pre.top()->val;
        TreeNode* node = pre.top()->left;
        pre.pop();
        while (node) {
            pre.push(node);
            node = node->right;
        }
        return val;
    }
    
    // 找小于target的nodes中最大最接近的那个
    void initPredecessor(TreeNode* node, double &target) {
        while (node) {
            if (node->val < target) {
                pre.push(node);
                node = node->right;
            } else if (node->val >= target) {
                node = node->left;
            }
        }
    }
    
    //  找大于等于target的nodes中最小最接近的那个
    void initSuccessor(TreeNode* node, double &target) {
        while (node) {
            if (node->val < target) {
                node = node->right;                
            } else if (node->val > target) {
                succ.push(node);
                node = node->left;
            } else {
                succ.push(node);
                return;
            }
        }
    }
    
private:
    stack<TreeNode*> pre, succ; // pre: <  succ: >=
};


class Solution {  // O(n)
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans(k);
        inorder(root, target, k);
        int i = 0, s1 = int(small.size()) - 1, l1 = 0;
        while (i < k && s1 >= 0 && l1 < large.size()) {
            if (target - small[s1] < large[l1] - target) {
                ans[i++] = small[s1--];
            } else {
                ans[i++] = large[l1++];
            }
        }
        while (i < k && s1 >= 0)  ans[i++] = small[s1--];
        while (i < k && l1 < large.size())  ans[i++] = large[l1++];  
        return ans;
    }
    
    void inorder(TreeNode* node, double &target, int &k) {
        if (!node)  return;
        inorder(node->left, target, k); // left subtree
        if (node->val < target)  small.push_back(node->val);
        else  large.push_back(node->val);
        if (large.size() >= k)  return;  // prune
        inorder(node->right, target, k);
    }
    
private:
    vector<int> small, large;
};
