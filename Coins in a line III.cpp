// 两人轮流从一组coins的两端取一个石子，问先手是或否保证values和最大

class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
     
    // dp[i][j] = sums[i..j] - min(dp[i + 1][j], dp[i][j - 1])
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int size = values.size();
        int dp[size + 1][size + 1];
        int sums[size + 1];
        for (int i = 1; i <= size; ++i) {
            sums[i] = sums[i - 1] + values[i - 1];
        }
        for (int i = size; i >= 1; --i) {
            dp[i][i] = values[i - 1];
            for (int j = i + 1; j <= size; ++j) {
                dp[i][j] = sums[j] - sums[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][size] > sums[size] / 2;
    }
};