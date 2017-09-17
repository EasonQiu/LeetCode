// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.

// Follow up:
// Could you solve it in O(nk) runtime?



// dp[i][j]: 表示第i间房间涂j色的最小成本
// dp[i][j] = costs[i][j] + min(dp[i - 1][k], k != j)
// 优化，预处理costs后用O(1) time去获得一个array中除了自己最小的num。即扫一遍记录最小两个值得index
// dp[i][j] = costs[i][j] + min_costs[i - 1][j];

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty())  return 0;
        int n = costs.size(), k = costs[0].size();
        if (n == 1)  return *min_element(costs[0].begin(), costs[0].end());
        if (k == 1)  return INT_MAX;
        vector<vector<int> > dp(n, vector<int>(k));
        dp[0] = costs[0];  // base case
        for (int i = 1; i < n; ++i) {
            // calculate the min_costs except itself in the previous array
            int min1 = 0, min2 = 0; // index for the two min costs
            (dp[i - 1][0] <= dp[i - 1][1]) ? min2 = 1 : min1 = 1;
            for (int j = 2; j < k; ++j) {
                if (dp[i - 1][j] <= dp[i - 1][min1]) {
                    min2 = min1;  min1 = j;
                } else if (dp[i - 1][j] < dp[i - 1][min2]) {
                    min2 = j;
                }
            }
            // dp function
            for (int j = 0; j < k; ++j) {
                dp[i][j] = costs[i][j] + ((j != min1) ? dp[i - 1][min1] : dp[i - 1][min2]);
            }
        }
        // final result
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};