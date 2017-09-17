// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// opt[i][j]表示p[0..i - 1]能否和s[0..j - 1]匹配
class Solution {
public:
  bool isMatch(string s, string p) {
  	int size1 = s.size(), size2 = p.size();
  	vector<vector<bool> > dp(size2 + 1, vector<bool>(size1 + 1));
  	dp[0][0] = true;
  	for (int i = 1; i <= size2; ++i) {
  		if (p[i - 1] == '*')  dp[i][0] = dp[i - 2][0];
  		for (int j = 1; j <= size1; ++j)  {
  			if (p[i - 1] != '*') { // 'a' or '.'
  				dp[i][j] = (p[i - 1] == s[j - 1] || p[i - 1] == '.') && dp[i - 1][j - 1];
  			} else if (p[i - 2] == '.') { // '.*'
  				dp[i][j] = dp[i - 2][j] || dp[i - 1][j] || dp[i][j - 1];
  			} else { // 'a*'
  				dp[i][j] = dp[i - 2][j] || dp[i - 1][j] || (dp[i][j - 1] && p[i - 2] == s[j - 1]);
  			}
  		}
  	}
  	return dp[size2][size1];
  }
};

int main() {
	Solution sol;
	cout << sol.isMatch("aab", "c*a*b") << endl;
}