// Given a string s and a string t, check if s is subsequence of t.
// You may assume that there is only lower case English letters in both s and t. t is potentially 
// a very long (length ~= 500,000) string, and s is a short string (<=100).
// A subsequence of a string is a new string which is formed from the original string by deleting 
// some (can be none) of the characters without disturbing the relative positions of the remaining 
// characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// s = "abc", t = "ahbgdc"
// Return true.

// Example 2:
// s = "axc", t = "ahbgdc"
// Return false.

// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one 
// by one to see if T has its subsequence. In this scenario, how would you change your code?

// 解法：opt(i,j)表示s的前i个字符是不是t的前j个字符的subsequence。
//      opt(i,j) = opt(i, j-1) || opt(i-1, j-1) if s[i]==t[j]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution2 { // simple version
public:
	bool isSubsequence(string s, string t) {
		// corner cases
		if (s == "")  return true;
		else if (t == "")  return false;
		// regular cases
		int i = 0;
		for (int j = 0; j < t.size(); ++j) {
		    if (s[i] == t[j])  ++i;
		    if (i == s.size())  return true;
		}
		return false;
	}
};

class Solution2 { // dp version
public:
	bool isSubsequence(string s, string t) { 
		// corner cases
		if (s == "")  return true;
		else if (t == "")  return false;
		// regular cases
		int s_size = s.size(), t_size = t.size();
		vector<vector<bool> > opt(s_size + 1, vector<bool>(2, true));
		for (int i = 1; i < s_size + 1; ++i)  opt[i][0] = false;
		for (int k = 0; k < t_size; ++k) {
			for (int i = 0; i < s_size; ++i) {
				opt[i + 1][1] = opt[i + 1][0]; // case 1
				if (s[i] == t[k] && !opt[i + 1][1]) { // case 2
					opt[i + 1][1] = opt[i][0];
				}
			}
			if (opt[s_size][1])  return true;
			for (int i = 0; i < s_size + 1; ++i)  opt[i][0] = opt[i][1];
		}
		return false;
	}
};

int main() {
	Solution sol;
	cout << sol.isSubsequence("abc", "ahbgdc") << endl;

	return 0;
}

