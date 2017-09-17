// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to right.

// Examples:

// Given binary tree [3,9,20,null,null,15,7],
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7
// return its vertical order traversal as:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS 再多存个index
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)  return vector<vector<int> >();
        unordered_map<int, vector<int> > map;
        int leftmost = 0, rightmost = 0;
        // level order traversal
        queue<TreeNode*> que;
        queue<int> index;
        que.push(root);  index.push(0);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                // get the top node
                TreeNode *node = que.front();
                int ix = index.front();
                que.pop();  index.pop();
                // operations on this node
                map[ix].push_back(node->val);
                if (node->left) {
                    que.push(node->left);   index.push(ix - 1);
                }
                if (node->right) {
                    que.push(node->right);  index.push(ix + 1);
                }
                // update the boundary
                leftmost = min(leftmost, ix);
                rightmost = max(rightmost, ix);
            }
        }
        // clear up the map
        vector<vector<int> > ans(rightmost - leftmost + 1, vector<int>());
        for (int i = leftmost; i <= rightmost; ++i) {
            ans[i - leftmost] = map[i];
        }
        return ans;
    }
};