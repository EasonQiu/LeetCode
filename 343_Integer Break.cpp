// Given a positive integer n, break it into the sum of at least two positive integers and 
// maximize the product of those integers. Return the maximum product you can get.

// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
// Note: You may assume that n is not less than 2 and not larger than 58.

// 解法：opt[i]表示和为i的最大乘积(可以只有一个integer)，计算1到n-1的opt[i]，再计算opt[n]

class Solution {
public:
  int integerBreak(int n) {
    vector<int> opt(n + 1);
    opt[0] = 1;
    // calculate max product from 1 to n-1
    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j <= i; ++j) {
    		opt[i] = max(opt[i], opt[i - j] * j);
    	}
    }
    // calculate the number n, ensure at least 2 numbers
    for (int j = 1; j < n; ++j) {
    	opt[n] = max(opt[n], opt[n - j] * j);
    }
    return opt[n];
  }
};