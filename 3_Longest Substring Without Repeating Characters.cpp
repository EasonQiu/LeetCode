// Given a string, find the length of the longest substring without repeating characters.

// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. 
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// 解法：sliding window，每次只要有一个字符重复就开始shrink收缩

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())  return 0;
		int dict[128] = {};
		int left = 0, max_len = 1;
		bool isRepeat = false;
		for (int right = 0; right < s.size(); ++right) {
			if (++dict[s[right]] > 1)  isRepeat = true;
			while (isRepeat) {
				if (--dict[s[left++]] == 1)  isRepeat = false;
			}
			max_len = max(max_len, right - left + 1);
		}
		return max_len;
	}
};

int main() {
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;

	return 0;
}