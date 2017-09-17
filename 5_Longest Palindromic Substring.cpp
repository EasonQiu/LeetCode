// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:
// Input: "babad"
// Output: "bab"

// Note: "aba" is also a valid answer.

// Example:
// Input: "cbbd"
// Output: "bb"


// 感想：判断是否是回文的时候不一定要从string两端向中间检测，也可以从中间向两端扩展
class Solution {
 public:
  string longestPalindrome(string s) {
  	max_len = 0;
  	for (int i = 0; i < s.size(); ++i) {
  		extendString(s, i, i);
  		extendString(s, i, i + 1);
  	}
  	return s.substr(start, max_len);
  }

  void extendString(string &s, int left, int right) {
  	while (left >= 0 && right < s.size() && s[left] == s[right]) {
  		--left;  ++right;
  	}
  	if (right - left - 1 > max_len) {
  		max_len = right - left - 1;
  		start = left + 1;
  	}
  }

 private:
 	int start, max_len;
};