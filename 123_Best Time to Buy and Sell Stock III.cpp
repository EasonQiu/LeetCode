// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock 
// before you buy again).

// opt[k][i]表示前i天最多用k次交易下的最大利润（第i天不一定要sell）
// opt[k][i] = max(opt[k][i - 1], prices[i] - prices[j] + opt[k - 1][j - 1]), j of [1, i -1]
//           = max(opt[k][i - 1], prices[i] + max(opt[k - 1][j - 1] - prices[j - 1]))

// 不一定非要执念于opt[i]就非得是end with day i，递推表达式可能还会存在优化的空间

class Solution {
public:
  int maxProfit(vector<int>& prices) {
  	if (prices.size() <= 1)  return 0;
  	int max_profit = 0, max_trans = 2;
  	vector<vector<int> > opt(max_trans + 1, vector<int>(prices.size() + 1));
  	for (int k = 1; k <= max_trans; ++k) {
  		int max_remain = INT_MIN;
  		for (int i = 2; i <= prices.size(); ++i) {
  			max_remain = max(max_remain, opt[k - 1][i - 2] - prices[i - 2]); // buy at i - 2
  			opt[k][i] = max(opt[k][i - 1], prices[i - 1] + max_remain); // sell at i - 1
  		}
  	}
  	return opt[max_trans][prices.size()];
  }
};