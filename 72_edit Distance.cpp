/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

// 本题的关键是送word1转换到word2，和word2转换到word1的步数相同。
// 如果同时改动两个word很难考虑，可以固定一个word2，只改动word1！
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        // init the base case
        for (int j = 0; j <= n; ++j)  dp[0][j] = j;
        for (int i = 0; i <= m; ++i)  dp[i][0] = i;
        // recursion
        for (int i = 1; i <= m; ++i) {
        	for (int j = 1; j <= n; ++j) {
        		if (word1[i - 1] == word2[j - 1]) {
        			dp[i][j] = dp[i - 1][j - 1];
        		} else {
        			dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        		}
        	}
        }
        return dp[m][n];
    }
};