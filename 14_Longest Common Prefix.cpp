// Write a function to find the longest common prefix string amongst an array of strings

// 更快速的方法是一个一个prefix检测过去而不是一个字符创一个字符串检测过去
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
  	if (strs.empty())  return "";
  	string prefix = strs[0];
  	int i, j;
  	for (i = 1; i < strs.size(); ++i) {
  		int prefix_size = min(prefix.size(), strs[i].size());
  		for (j = 0; j < prefix_size; ++j) {
  			if (strs[i][j] != prefix[j])  break;
  		}
  		prefix = prefix.substr(0, j);
  	}
  	return prefix;
  }
};