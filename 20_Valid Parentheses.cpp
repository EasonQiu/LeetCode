// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" 
// and "([)]" are not.

class Solution {
public:
  bool isValid(string s) {
  	stack<char> stack;
  	for (int i = 0; i < s.size(); ++i) {
  		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
  			stack.push(s[i]);
  		} else {
  			if (stack.empty() || 
  				  (s[i] == ')' && stack.top() != '(') ||
  				  (s[i] == '}' && stack.top() != '{') || 
  				  (s[i] == ']' && stack.top() != '['))  return false;
  			stack.pop();
  		}
  	}
  	return stack.empty();
  }
};