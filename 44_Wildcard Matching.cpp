// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false


// dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == '?' || p[i - 1] == s[j - 1]), if p[i - 1] != '*'
//  					dp[i - 1][j] || dp[i][j - 1], if p[i - 1] == '*' 
// trick: 记住*可以match任意长度的字符串时该怎么处理
class Solution {
public:
  bool isMatch(string s, string p) {
  	int size1 = s.size(), size2 = p.size();
  	bool dp[size2 + 1][size1 + 1] = {};
  	// base case
  	dp[0][0] = true;
  	// fill the array
  	for (int i = 1; i <= size2; ++i) {
      dp[i][0] = dp[i - 1][0] && p[i - 1] == '*';  // corner cases得注意！如"aa", "*"
  		for (int j = 1; j <= size1; ++j) {
  			if (p[i - 1] != '*') {
  				dp[i][j] = dp[i - 1][j - 1] && (p[i - 1] == '?' || p[i - 1] == s[j - 1]);
  			} else {
  				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
  			}
  		}
  	}
  	// final result
  	return dp[size2][size1];
  }
};