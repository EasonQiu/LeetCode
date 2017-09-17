// Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

// Example 1:
// Input: "sea", "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Note:
// The length of given words won't exceed 500.
// Characters in given words can only be lower-case letters.


class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1));
        // base cases
        for (int j = 1; j <= size2; ++j)  dp[0][j] = j;
        for (int i = 1; i <= size1; ++i)  dp[i][0] = i;
        // regular cases
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // final result
        return dp[size1][size2];
    }
};