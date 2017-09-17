// There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.

// Could you please decide the first player will win or lose?

// Have you met this question in a real interview? Yes
// Example
// Given values array A = [1,2,2], return true.

// Given A = [1,2,4], return false.

class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    // dp[i]: 从index = i的石子往后取，先手能获得的最大values
    // dp[i] = sums[i] - min(dp[i + 1], dp[i + 2])
    bool firstWillWin(vector<int> &values) {
        // write your code here
        if (values.size() <= 1)  return true;
        int size = values.size();
        int dp[size] = {0};
        int sums[size + 1] = {0};
        for (int i = size - 1; i >= 0; --i) {
            sums[i] = sums[i + 1] + values[i];
        }
        dp[size - 1] = values[size - 1];
        dp[size - 2] = values[size - 1] + values[size - 2];
        for (int i = size - 3; i >= 0; --i) {
            dp[i] = sums[i] - min(dp[i + 1], dp[i + 2]);
            cout << dp[i] << " ";
        }
        return dp[0] > sums[0] / 2;
    }
};