// Given a non-empty string s and a dictionary wordDict containing a list of non-empty 
// words, add spaces in s to construct a sentence where each word is a valid dictionary word. 
// You may assume the dictionary does not contain duplicate words.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].

// opt[i]是一个vector，记录所有前一个有效单词的最后一个字符的index
// opt[i] = {j if opt[j]非空且s.substr(j + 1, i - j)}
// 一定要有valid_index，不然时间复杂度就是完全的O(n^2)

//  0 1 2 3
//    c a t
//  j     i
// dp[i] stores indices that s.substr(j, i - j) in dict and dp[j] != NULL
class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    if (wordDict.empty() || s.size() == 0)  return vector<string>();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<vector<int> > opt(s.size() + 1, vector<int>());
    vector<int> valid_index;
    // base case
    valid_index.push_back(0);
    // fill the opt array
    for (int i = 1; i <= s.size(); ++i) {
      for (int j : valid_index) {
        if (dict.find(s.substr(j, i - j)) != dict.end()) {
          opt[i].push_back(j);
        }
      }
      if (opt[i].size() > 0)  valid_index.push_back(i);
    }
    // trace back to get all the solutions
    vector<string> solution, ans;
    dfs(opt, s, s.size(), solution, ans);
    // final result
    return ans;
  }

  void dfs(const vector<vector<int> > &opt, const string &s, int index, 
           vector<string> &solution, vector<string> &ans) {
    // base case
    if (index == 0) {
      string one_ans = solution[0];
      for (int i = 1; i < solution.size(); ++i) {
        one_ans = solution[i] + " " + one_ans;
      }
      ans.push_back(one_ans);
      return;
    }
    // normal case
    for (int i = 0; i < opt[index].size(); ++i) {
      solution.push_back(s.substr(opt[index][i], index - opt[index][i]));
      dfs(opt, s, opt[index][i], solution, ans);
      solution.pop_back();
    }
  }
};