class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2 == 1)  return 0;
        S = (sum + S) / 2;
        // dp recursion
        vector<int> dp(S + 1);
        dp[0] = 1;
        for (int n : nums) {
            for (int j = S; j >= n; --j) {
                dp[j] += dp[j - n];
            }
        }
        return dp[S];
    }
};