// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

class Solution {
public:
  vector<vector<string>> partition(string s) {
    if (s.empty())  return vector<vector<string> >();
    vector<vector<string> > ans;
    vector<string> one_ans;
    backtrack(s, 0, one_ans, ans);
    return ans;
  }

  void backtrack(string &s, int i, vector<string> &one_ans, vector<vector<string> > &ans) {
    if (i == s.size()) {
      ans.push_back(one_ans);
      return;
    }
    for (int j = i; j < s.size(); ++j) {
      if (s[j] != s[i]) continue;
      if (isPlindrome(s, i, j)) {
        one_ans.push_back(s.substr(i, j - i + 1));
        backtrack(s, j + 1, one_ans, ans);
        one_ans.pop_back();
      }
    }
  }

  bool isPlindrome(string &s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--])  return false;
    }
    return true;
  }
};