// You need to construct a binary tree from a string consisting of parenthesis and integers.

// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

// You always start to construct the left child node of the parent first if it exists.

// Example:
// Input: "4(2(3)(1))(6(5))"
// Output: return the tree root node representing the following tree:

//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
// Note:
// There will only be '(', ')', '-' and '0' ~ '9' in the input string.
// An empty tree is represented by "" instead of "()".

class Solution {  // O(n)
public:
    TreeNode* str2tree(string s) {
        if (s == "")  return NULL;
        int i = 0;
        return build(s, i);
    }
    
    TreeNode* build(string &s, int &i) {
        // parse the int
        int j = i;
        while (j < s.size() && s[j] != '(' && s[j] != ')')  ++j;
        TreeNode* node = new TreeNode(stoi(s.substr(i, j - i)));
        i = j;
        // build its subtree
        if (s[i] == '(') { // left child
            node->left = build(s, ++i);
            ++i;  // )
        }
        if (i < s.size() && s[i] == '(') { // right child
            node->right = build(s, ++i);
            ++i;
        }
        return node;
    }
};

class Solution {  // O(nlogn)
public:
    TreeNode* str2tree(string s) {
        if (s == "")  return NULL;
        // parse the int
        int left = 0;
        while (left < s.size() && s[left] != '(' && s[left] != ')')  ++left;
        TreeNode* node = new TreeNode(stoi(s.substr(0, left)));
        if (left == s.size())  return node;
        // find the left part
        int count_paren = 1;
        int right = left;
        while (count_paren != 0) {
            ++right;
            if (s[right] == '(') {
                ++count_paren;
            } else if (s[right] == ')') {
                --count_paren;
            }
        }
        node->left = str2tree(s.substr(left + 1, right - left - 1));
        // find the right part
        if (++right != s.size()) {
            node->right = str2tree(s.substr(right + 1, s.size() - right - 2));
        }
        return node;
    }
};