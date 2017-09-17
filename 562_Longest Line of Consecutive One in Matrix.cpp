// Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

// Example:
// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3
// Hint: The number of elements in the given matrix will not exceed 10,000.


// dp[i][j]: 0..3 -> row, col, diag, anti-diag
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty())  return 0;
        int row = M.size(), col = M[0].size();
        int max_line = 0;
        vector<vector<vector<int> > > dp(row, vector<vector<int> >(col, vector<int>(4)));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (M[i][j] == 0)  continue;
                dp[i][j][0] = (j > 0) ? 1 + dp[i][j - 1][0] : 1;
                dp[i][j][1] = (i > 0) ? 1 + dp[i - 1][j][1] : 1;
                dp[i][j][2] = (i > 0 && j > 0) ? 1 + dp[i - 1][j - 1][2] : 1;
                dp[i][j][3] = (i > 0 && j + 1 < col) ? 1 + dp[i - 1][j + 1][3] : 1;
                max_line = max(max_line, max(max(dp[i][j][0], dp[i][j][1]), 
                                             max(dp[i][j][2], dp[i][j][3])));
            }
        }
        return max_line;
    }
};