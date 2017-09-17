// dp[j][i]: s[j...i]的最长回文子集
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() <= 1)  return s.size();
        int size = s.size();
        vector<vector<int> > dp(size, vector<int>(size));
        // base case
        for (int i = 0; i < size; ++i)  dp[i][i] = 1;
        // normal case
        for (int i = 1; i < size; ++i) { // right
            for (int j = i - 1; j >= 0; --j) { // left
                if (s[j] == s[i]) {
                    dp[j][i] = 2 + dp[j + 1][i - 1];
                } else {
                    dp[j][i] = max(dp[j + 1][i], dp[j][i - 1]);
                }
            }
        }
        return dp[0][size - 1];
    }
};