// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

// 解法：opt(i) = opt(i - 1) + (opr(i - 2) if 二位数小于26)

class Solution {
public:
	int numDecodings(string s) {
		// corner case
		if (s == "" || s[0] == '0')  return 0;
		// base case
		vector<int> opt(s.size() + 1);
		opt[0] = 1;  opt[1] = 1;
		// fill the array
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '0') {
				if (s[i - 1] != '1' && s[i - 1] != '2')  return 0;
				opt[i + 1] = opt[i - 1];
				continue;
			}
			opt[i + 1] = opt[i];
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - '0' <= 6)) {
				opt[i + 1] += opt[i - 1];
			}
		}
		// final result
		return opt[s.size()];
	}
};