// You are given coins of different denominations and a total amount of money amount. 
// Write a function to compute the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note: You may assume that you have an infinite number of each kind of coin.

// 解法：opt[i]表示amount为i时所需的最小硬币个数

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
  	if (coins.size() == 0 || amount < 0)  return -1;
  	vector<int> opt(amount + 1, INT_MAX);
  	// base case
  	opt[0] = 0;
  	// fill the array
  	for (int i = 1; i <= amount; ++i) {
  		for (int j = 0; j < coins.size(); ++j) {
  			if (i - coins[j] >= 0 && opt[i - coins[j]] != -1) {
  				opt[i] = min(opt[i], opt[i - coins[j]] + 1);
  			}
  		}
  		if (opt[i] == INT_MAX)  opt[i] = -1;
  	}
  	// final result
  	return opt[amount];
  }
};