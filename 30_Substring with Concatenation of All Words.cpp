// You are given a string, s, and a list of words, words, that are all of 
// the same length. Find all starting indices of substring(s) in s that is 
// a concatenation of each word in words exactly once and without any 
// intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]
// You should return the indices: [0,9].

// 解法：重复做word_len遍sliding window，每次left和right往后移动yige单词的长度

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		// corner cases
		if (words.size() == 0)  return ans;
		int word_len = words[0].size(), words_num = words.size();
		if (word_len * words_num > s.size())  return ans;
		// create hashmap for words
		unordered_map<string, int> dictory;
		for (string word : words)  ++dictory[word];
		for (int k = 0; k < word_len; ++k) {
			unordered_map<string, int> dict = dictory;
			int count = words_num;
			for (int left = k, right = k; right + word_len <= s.size(); right += word_len) {
				// expand
				if (--dict[s.substr(right, word_len)] >= 0)  --count;
				if (right - left == (words_num - 1) * word_len) {
					// find one solution
					if (count == 0)  ans.push_back(left);
					// shrink
					if (++dict[s.substr(left, word_len)] > 0)  ++count;
					left += word_len;
				}
			}
		}
		// final answer
		return ans;
	}
};

int main() {
	string s = "barfoothefoobarman";
	vector<string> words = {"foo", "bar"};
	Solution sol;

	vector<int> ans = sol.findSubstring(s, words);
	for (int n : ans) cout << n << " ";
	cout << endl;

	return 0;
}