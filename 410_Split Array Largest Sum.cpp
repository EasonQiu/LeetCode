// Given an array which consists of non-negative integers and an integer m, you can split 
// the array into m non-empty continuous subarrays. Write an algorithm to minimize the 
// largest sum among these m subarrays.

// Note:
// If n is the length of array, assume the following constraints are satisfied:
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)

// Examples:
// Input:
// nums = [7,2,5,10,8]
// m = 2
// Output:
// 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

// opt[k][i] denotes the minmax subarray sum of the first i numbers that is split into k parts
// opt[k][i] = min(max(opt[k - 1][j - 1], opt[1][i] - opt[1][j - 1])), j from [k, i]
// attention: min不能用nums.size()
// dp不是最优解，用二分法解在单个最大值和数组和之间

class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    int size = nums.size();
  	m = max(1, min(size, m));
  	vector<vector<int> > opt(2, vector<int>(size + 1));
  	// base case
  	for (int i = 1; i <= size; ++i) {
  		opt[0][i] = opt[0][i - 1] + nums[i - 1];
  	}
  	// fill the array
  	for (int k = 2; k <= m; ++k) {
  		for (int i = k; i <= size; ++i) {
  			opt[1][i] = INT_MAX;
  			for (int j = k; j <= i; ++j) {
  				opt[1][i] = min(opt[1][i], max(opt[0][j - 1], opt[0][i] - opt[0][j - 1]));
  			}
  		}
  	}
  	// final result
  	return opt[m][size];
  }
};

class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    int size = nums.size();
  	m = max(1, min(size, m));
  	vector<vector<int> > opt(m + 1, vector<int>(size + 1));
  	// base case
  	for (int i = 1; i <= size; ++i) {
  		opt[1][i] = opt[1][i - 1] + nums[i - 1];
  	}
  	// fill the array
  	for (int k = 2; k <= m; ++k) {
  		for (int i = k; i <= size; ++i) {
  			opt[k][i] = INT_MAX;
  			for (int j = k; j <= i; ++j) {
  				opt[k][i] = min(opt[k][i], max(opt[k - 1][j - 1], opt[1][i] - opt[1][j - 1]));
  			}
  		}
  	}
  	// final result
  	return opt[m][size];
  }
};