// Given two strings s1 and s2, write a function to return true if s2 contains 
// the permutation of s1. In other words, one of the first string's permutations 
// is the substring of the second string.

// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").

// 解法：Sliding Window + Hashmap
// 感想：c类型数组的初始化方法为int dict[128] = {}，否则初始值不是0

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())  return false;
		int dict[128] = {};
		for (unsigned int i = 0; i < s1.size(); ++i)  ++dict[s1[i]];
		unsigned int left = 0, right, count = s1.size();
		for (right = 0; right < s2.size(); ++right) {
			if (--dict[s2[right]] >= 0)  --count;
			if (right - left + 1 == s1.size()) {
				if (count == 0)  return true;
				if (++dict[s2[left++]] > 0)  ++count;
			}
		}
		return false;
  }
};

int main() {
	Solution sol;
	cout << sol.checkInclusion("ab", "eidbaooo") << endl;

	return 0;
}