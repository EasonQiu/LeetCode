// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock 
// before you buy again).

// pay attention to corner case: when k >= size / 2, you can gain every profit
// you should consider space complecity when facing large k

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
  	if (prices.size() <= 1)  return 0;
  	int max_profit = 0;
  	// corner case
  	if (k >= prices.size() / 2) {
  		for (int i = 1; i < prices.size(); ++i) {
  			if (prices[i] > prices[i - 1])  max_profit += prices[i] - prices[i - 1];
  		}
  		return max_profit;
  	}
  	// normal case
  	vector<vector<int> > opt(2, vector<int>(prices.size() + 1));
  	for (int kk = 1; kk <= k; ++kk) {
  		int max_remain = INT_MIN;
  		for (int i = 2; i <= prices.size(); ++i) {
  			max_remain = max(max_remain, opt[0][i - 2] - prices[i - 2]); // buy at i - 2
  			opt[1][i] = max(opt[1][i - 1], prices[i - 1] + max_remain); // sell at i - 1
  		}
  		swap(opt[0], opt[1]);
  	}
  	return opt[0][prices.size()];
  }
};