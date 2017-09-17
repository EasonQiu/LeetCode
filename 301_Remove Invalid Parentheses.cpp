// Remove the minimum number of invalid parentheses in order to make the input string valid. 
// Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Examples:
// "()())()" -> ["()()()", "(())()"]
// "(a)())()" -> ["(a)()()", "(a())()"]
// ")(" -> [""]


// 验证valid的方式是：
// 从左往右扫保证(一直>=),即每一个出现的)都能保证在之前找到一个匹配的(
// 从右往左扫保证)一直>=(,即每一个出现的(都能保证在之后找到一个匹配的)
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, 0, 0, bracket1, ans);
        return ans;
    }
    
    void remove(string s, int pre_end, int pre_del, vector<char> &bracket, vector<string> &ans) {
        int stack = 0;
        for (int i = pre_end; i < s.size(); ++i) {
            if (s[i] == bracket[0])  ++stack;
            if (s[i] == bracket[1])  --stack;
            if (stack >= 0)  continue;
            for (int j = pre_del; j <= i; ++j) { // to delete one bracket[1]
                if (s[j] == bracket[1] && s[j - 1] != bracket[1]) {
                    remove(s.substr(0, j) + s.substr(j + 1), i, j, bracket, ans);   
                }
            }
            return;
        }
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        if (bracket[0] == '(') { // finish checking from left to right, eg. all ) has its pair( before
            remove(reverse_s, 0, 0, bracket2, ans);
        } else {
            ans.push_back(reverse_s);
        }
    }

private:
    vector<char> bracket1 = {'(', ')'};
    vector<char> bracket2 = {')', '('};
};