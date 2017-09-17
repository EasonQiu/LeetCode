// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
// determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
// You may assume the dictionary does not contain duplicate words.

// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// Return true because "leetcode" can be segmented as "leet code".

// 解法：opt[i]: 以nums[i - 1]为结尾的最后一个单词所能成功分割的最大单词个数
//      opt[i] = max(opt[j] + 1 if s.substr(j, i - j)在dict里面)


class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    if (s.empty() || wordDict.empty())  return false;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> valid_index;
    valid_index.push_back(-1);
    for (int i = 0; i < s.size(); ++i) {
      for (int j : valid_index) {
        if (dict.find(s.substr(j + 1, i - j)) != dict.end()) {
          valid_index.push_back(i);
          break;
        }
      }
    }
    return valid_index.back() == s.size() - 1;
  }
};