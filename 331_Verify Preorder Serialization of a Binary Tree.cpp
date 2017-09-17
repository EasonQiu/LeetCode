// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

// Example 1:
// "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Return true

// Example 2:
// "1,#"
// Return false

// Example 3:
// "9,#,#,1"
// Return false

// corner case: "1,#,#,1"
// 一个number必须要有左右两边相配
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int ix = 0;
        if (!check(preorder, ix))  return false;
        return ix >= preorder.size();
    }
    
    bool check(string &s, int &i) {
        if (i >= s.size())  return false;
        if (s[i] == '#') {
            i = i + 2;  return true;
        }
        i = findComma(s, i) + 1;
        if (!check(s, i))   return false;
        return check(s, i);
    }
    
    int findComma(string &s, int i) {
        int j = i + 1;
        while (j < s.size() && s[j] != ',')  ++j;
        return j;
    }
};

class Solution { // stack
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "")  return false;
        if (preorder == "#")  return true;
        stack<int> stack;
        int i = 0;
        while (i < preorder.size()) {
            if (preorder[i] != '#') {
                stack.push(2);
            } else {
                if (stack.empty())  return false;
                while (--stack.top() == 0) {
                    stack.pop();
                    if (stack.empty()) { // two childs of root found
                        return findComma(preorder, i) + 1 >= preorder.size();
                    }
                }
            }
            i = findComma(preorder, i) + 1;
        }
        return stack.empty();
    }
    
    int findComma(string &s, int i) {
        int j = i + 1;
        while (j < s.size() && s[j] != ',')  ++j;
        return j;
    }
};
