// Given an integer array with all positive numbers and no duplicates, find the number 
// of possible combinations that add up to a positive integer target.

// Example:
// nums = [1, 2, 3]
// target = 4
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Therefore the output is 7.

// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers?

// 解法：opt[i] = sum(opt[i - nums[j]])
// C++ template for ALL Combination Problem Set:
//   https://discuss.leetcode.com/topic/52542/c-template-for-all-combination-problem-set

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> opt(target + 1);
    // base case
    opt[0] = 1;
    // fill the array
    for (int i = 1; i <= target; ++i) {
    	for (int j = 0; j < nums.size(); ++j) {
    		if (i - nums[j] >= 0)  opt[i] += opt[i - nums[j]];
    	}
    }
    return opt[target];
  }
};