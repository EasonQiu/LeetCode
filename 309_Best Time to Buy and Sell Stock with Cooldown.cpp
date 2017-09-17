// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions 
// as you like (ie, buy one and sell one share of the stock multiple times) with the following 
// restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock 
// before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

// 解法：sell[i]: 第i天为sell的最大利润  max(sell[i - 1], buy[i - 1]) + diff price
//      buy[i]:  第i天为buy的最大利润   max(buy[i - 1], sell[i - 2])


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1)  return 0;
    vector<int> buy(prices.size() + 1), sell(prices.size() + 1);
    int max_profit = 0;
    // fill the array
    for (int i = 1; i < prices.size(); ++i) {
    	sell[i + 1] = max(sell[i] + buy[i]) + prices[i] - prices[i - 1];
    	buy[i + 1]  = max(buy[i], sell[i - 1]);
    	max_profit  = max(max_profit, sell[i + 1]);
    }
    return max_profit;
  }
};


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1)  return 0;
    vector<int> buy(prices.size()), sell(prices.size());
    int max_profit = 0, pre_max_profit = 0;
    // fill the array
    for (int i = 1; i < prices.size(); ++i) {
    	// update sell array
    	for (int j = 0; j < i; ++j) {
    		sell[i] = max(sell[i], buy[j] + prices[i] - prices[j]);
    	}
    	// update buy array
    	buy[i] = pre_max_profit;
    	pre_max_profit = max(pre_max_profit, sell[i - 1]);
    	// update the max_profit
    	max_profit = max(max_profit, sell[i]);
    }
    return max_profit;
  }
};