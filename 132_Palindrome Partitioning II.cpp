// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

// 感想：你在分割成子问题的时候，一定要保证两个计算结果中的其中一个是很容易计算的，和原问题类型不同的子问题。
//      比如这道问题中，你把计算f[0][size - 1]分割成f[0][k] + f[k + 1][size - 1] + 1并不是最优要O(n^3)。
//      其实你只需要计算从idnex为0开始substring，切割成的后半部分的计算结果只是判断子串是否为palindrome

// opt[j] = min(opt[i - 1] + 1 if s.substr(i, j - i + 1) is palindrome), i from [0, j]
// 快速判断是否子串为回文要求开二维数组存储是否子串的结果，且填表顺序要求从左往右
class Solution {
public:
  int minCut(string s) {
  	// corner case
  	if (s.size() <= 1)  return 0;

  	int size = s.size();
  	vector<int> opt(size + 1);
  	vector<vector<bool> > is_palin(size, vector<bool>(size));
  	// base case
  	opt[0] = -1;
  	// fill the array
  	for (int j = 0; j < size; ++j) { // j is the index of last char
  		opt[j + 1] = j;
  		for (int i = 0; i <= j; ++i) {
  			if (s[i] == s[j] && (j - i <= 2 || is_palin[i + 1][j - 1])) {
  				is_palin[i][j] = true;
  				opt[j + 1] = min(opt[j + 1], opt[i] + 1);
  			}
  		}
  	}
  	// final result
  	return opt[size];
  }
};


// not a good solution cuz you don't need to compute the min cut of substrings,
// we only need to check those substring starting from index 0
// f[i][j] denotes the min cut of substring from i to j
// f[i][j] = min(f[i][k - 1] + f[k][j] + 1 if k from [i + 1, j],
//							 s.substr(i, j - i + 1) is palindrome ? 0 : j - i)
// return f[0][size - 1]
class Solution {
public:
  int minCut(string s) {
  	// corner case
  	if (s.size() <= 1)  return 0;
  	// normal case
  	int size = s.size();
  	vector<vector<int> > dp(size, vector<int>(size));
  	for (int i = size - 1; i >= 0; --i) {
  		int min_cut = 
  		for (int j = i; j <= size - 1; ++j) {
  			if (i == j) {
  				dp[i][j] = 0;  continue;
  			}
  			// check if the current substring is palindrome
  			bool is_palindrome = s[i] == s[j];
  			if (is_palindrome && j - i > 2)  is_palindrome = dp[i + 1][j - 1] == 0;
  			if (is_palindrome) {
  				dp[i][j] = 0;  continue;
  			} else {
  				dp[i][j] = j - i;
  			}
  			// find the min cut of the current substring
  			for (int k = i + 1; k <= j; ++k) {
  				dp[i][j] =  min(dp[i][j], dp[i][k - 1] + dp[k][j] + 1);
  			}
  		}
  	}
  	// final result
  	return dp[0][size - 1];
  }
};