// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

// Example 1:
// Input:
// s = "aaabb", k = 3
// Output:
// 3
// The longest substring is "aaa", as 'a' is repeated 3 times.

// Example 2:
// Input:
// s = "ababbc", k = 2
// Output:
// 5
// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 因为如果这个character的数量小于k，那么answer中一定没有这个character，可以将数组split
// 扫一遍数组统计count，以所有count小于k的character为基准split数组
// trick：如果substr(begin, len)中begin等于size / len等于0会返回空串
class Solution {
public:
  int longestSubstring(string s, int k) {
  	if (s == "")  return 0;
  	// count the number of characters
  	int dict[26] = {};
  	for (char c : s)  ++dict[c - 'a'];
  	// split the s if character is not valid
  	int split = 0, max_len = INT_MIN;
  	for (int i = 0; i < s.size(); ++i) {
  		if (dict[s[i] - 'a'] < k) {
  			max_len = max(max_len, longestSubstring(s.substr(split, i - split), k));
  			split = i + 1;
  		}
  	}
  	// final result
  	if (split == 0) { // find one solution
  		return s.size();
  	} else { // test last substring
  		return max(max_len, longestSubstring(s.substr(split), k));
  	}
  }
};

int main() {
	Solution s;
	cout << s.longestSubstring("ababbc", 2) << endl;
}