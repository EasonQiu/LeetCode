// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.


// opt[i][j] denotes if s1[0...i-1] and s2[0...j-1] can form s3[0...i+j-1]
// opt[i][j] = (opt[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
//						 (opt[i][j - 1] && s2[j - 1] == s3[i + j - 1])
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
  	if (s1.size() + s2.size() != s3.size())  return false;
  	int size1 = s1.size(), size2 = s2.size();
  	vector<vector<bool> > opt(size1 + 1, vector<bool>(size2 + 1));
  	// base case
  	opt[0][0] = true;
  	// fill the array
  	for (int i = 0; i <= size1; ++i) {
  		for (int j = 0; j <= size2; ++j) {
  			if (i == 0 && j == 0)  continue;
  			if (i > 0)  opt[i][j] = opt[i - 1][j] && s1[i - 1] == s3[i + j - 1];
  			if (j > 0)  opt[i][j] = opt[i][j] || (opt[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
  		}
  	}
  	// fianl result
  	return opt[size1][size2];
  }
};