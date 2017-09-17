// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

// Two trees are duplicate if they have the same structure with same node values.

// Example 1: 
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:
//       2
//      /
//     4
// and
//     4
// Therefore, you need to return above trees' root in the form of a list.


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>  dict; // <tree pattern, counter>
        vector<TreeNode*> ans;
        traverse(root, dict, ans);
        return ans;
    }
    
    string traverse(TreeNode* node, unordered_map<string, int> &dict, vector<TreeNode*> &ans) {
        if (!node)  return "#";
        string pattern = to_string(node->val) + ' ' + 
                         traverse(node->left, dict, ans) + ' ' + traverse(node->right, dict, ans);
        if (++dict[pattern] == 2)  ans.push_back(node);
        return pattern;
    }
};


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        vector<TreeNode*> ans;
        for (auto &pair : paired) {
            for (TreeNode* node : pair.second) {
                ans.push_back(node);
            }
        }
        return ans;
    }
    
    void traverse(TreeNode* node) {
        if (!node)  return;
        auto pos = paired.find(node->val);
        bool is_find = false;
        if (pos != paired.end()) {
            for (TreeNode* pair_root : pos->second) {
                if (!SameTree(node, pair_root))  continue;
                is_find = true;  break;
            }
        }
        if (!is_find) {
            pos = unpaired.find(node->val);
            if (pos != unpaired.end()) {
                for (int i = 0; i < pos->second.size(); ++i) {
                    if (!SameTree(node, pos->second[i]))  continue;
                    paired[node->val].push_back(node);
                    pos->second.erase(pos->second.begin() + i);
                    is_find = true;  break;
                }
            }
            if (!is_find) unpaired[node->val].push_back(node);
        }
        traverse(node->left);
        traverse(node->right);
    }
    
    bool SameTree(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2)  return true;
        if (!n1 || !n2)  return false;
        if (n1->val != n2->val)  return false;
        if (!SameTree(n1->left, n2->left))  return false;
        return SameTree(n1->right, n2->right);
    }
    
private:
    // paired: <node->val, roots of different trees>
    // unpaired: <node->val, roots of unpaired trees>
    unordered_map<int, vector<TreeNode*> > paired, unpaired;
};