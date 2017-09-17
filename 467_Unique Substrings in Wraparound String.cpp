// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
// so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// Now we have another string p. Your job is to find out how many unique non-empty substrings of p 
// are present in s. In particular, your input is the string p and you need to output the number of 
// different non-empty substrings of p in the string s.
// Note: p consists of only lowercase English letters and the size of p might be over 10000.

// Example 1:
// Input: "a"
// Output: 1
// Explanation: Only the substring "a" of string "a" is in the string s.
// Example 2:
// Input: "cac"
// Output: 2
// Explanation: There are two substrings "a", "c" of string "cac" in the string s.
// Example 3:
// Input: "zab"
// Output: 6
// Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.

// 解法：vector(26)去保存这个字符为结尾的最长子串，最终vector的和就是解
//      opt(i)表示以第i个字符为结尾的最长字符串，opt(i) = 1 or opt(i - 1)
// 感想：（1）substr这类题目常见的子问题分割方法是以当前字符为结尾的字符串，因为这样很容易加上后面一个字符就是新字符串。
//      （2）计算dp递推表达式时，可以加辅助的变量，如这题中的currMaxLen。
//      （3）dp最终返回的值不一定就是dp数组中存储的最后一个值，可能是最后一组数据的求和或求最大，也可能是对整个数组进行相关操作。
//      （4）hashset去重是最直接的思路，但存储string的时候其实只需存结尾的字符和与之对应的maxLen，由于结尾字符有限所以转换成数组。
//      （5）因为这题有一个隐含的技巧，hashset中的字符串是有规律的存在的，即abc存在则bc和c一定存在，所以只需存储最长的字符串。

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		if (p.size() <= 1)  return p.size();
		int max_len[26] = {}, curr_max_len = 1; // max_len function as hashset
		// calculate each letter as the end of substring
		++max_len[p[0] - 'a'];
		for (int i = 1; i < p.size(); ++i) {
			if ((p[i - 1] - 'a' + 1) % 26 != (p[i] - 'a') % 26)  curr_max_len = 1;
			else  ++curr_max_len;
			max_len[p[i] - 'a'] = max(curr_max_len, max_len[p[i] - 'a']);
		}
		// sum up all substrings
		int sum = 0;
		for (int i = 0; i < 26; ++i)  sum += max_len[i];
		// final result
		return sum;
	}
};