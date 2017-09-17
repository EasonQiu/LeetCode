// Given n pairs of parentheses, write a function to generate all combinations of 
// well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 初始化一个一定长度的string，需要后面加上任意字符，不能只写size
// string str(2 * n, '.');
class Solution {
public:
  vector<string> generateParenthesis(int n) {
  	vector<string> ans;
  	if (n == 0)  return ans;
  	string str(2 * n, '.');
  	dfs(str, 0, n, n, 0, ans);
  	return ans;
  }

  void dfs(string &str, int i, int left, int right, int stack, vector<string> &ans) {
  	if (i == str.size()) {
  		ans.push_back(str);  return;
  	}
  	if (stack > 0) {
  		if (left > 0) {
  			str[i] = '(';  dfs(str, i + 1, left - 1, right, stack + 1, ans);
  		}
  		if (right > 0) {
  			str[i] = ')';  dfs(str, i + 1, left, right - 1, stack - 1, ans);
  		}
  	} else {
  		str[i] = '(';  dfs(str, i + 1, left - 1, right, stack + 1, ans);
  	}
  }
};