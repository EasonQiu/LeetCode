// Given a string containing just the characters '(' and ')', find the length of the 
// longest valid (well-formed) parentheses substring.

// For "(()", the longest valid parentheses substring is "()", which has length = 2.

// Another example is ")()())", where the longest valid parentheses substring is "()()", 
// which has length = 4.

// opt[i] denotes the longest len of substring ending with s[i - 1]
// opt[i] = 0 if s[i - 1] == '('
//          opt[i - 1] + 2 if s[i - 2, i - 1] == '()'
//          opt[i - 1] + 2 if s[i - 2, i -1] == '))' && opt[i - 1] != 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int size = s.size();
    int opt[size + 1] = {0};
    int max_len = 0;
    for (int i = 2; i <= size; ++i) {
      if (s[i - 1] == '(')  continue;
      if (s[i - 2] == '(') { // '....()'
        opt[i] = 2 + opt[i - 2];
      } else { // '...))'
        if (opt[i - 1] == 0)  continue;
        if (i - opt[i - 1] - 2 >= 0 && s[i - opt[i - 1] - 2] == '(') 
          opt[i] = 2 + opt[i - 1] + opt[i - opt[i - 1] - 2];
      }
      max_len = max(max_len,  opt[i]);
    }
    return max_len;
  }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
    	int n = s.size();
        vector<int> dp(n);
        // leftIx is the index of ( that hasn't found a pair
        int maxLen = 0, leftIx;
        for (int i = 1; i < n; ++i) {
        	if (s[i] == ')') {
        		leftIx = i - 1 - dp[i - 1];
        		if (leftIx >= 0 && s[leftIx] == '(')
        			dp[i] = dp[i - 1] + 2 + ((leftIx - 1 >= 0) ? dp[leftIx - 1] : 0);
        		maxLen = max(maxLen, dp[i]);
        	}
        }
        return maxLen;
    }
};

int main() {
	Solution s;
	cout << s.longestValidParentheses("()(()") << endl;
	return 0;
}