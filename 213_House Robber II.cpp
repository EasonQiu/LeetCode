// You are a professional robber planning to rob houses along a street. Each house has 
// a certain amount of money stashed, the only constraint stopping you from robbing each 
// of them is that adjacent houses have security system connected and it will automatically 
// contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, 
// determine the maximum amount of money you can rob tonight without alerting the police.

// After robbing those houses on that street, the thief has found himself a new place for 
// his thievery so that he will not get too much attention. This time, all houses at this 
// place are arranged in a circle. That means the first house is the neighbor of the last one. 
// Meanwhile, the security system for these houses remain the same as for those in the previous 
// street.

// Given a list of non-negative integers representing the amount of money of each house, 
// determine the maximum amount of money you can rob tonight without alerting the police.

// 解法：yes[i]表示偷第i间house的最大收益； no[i]表示不偷第i间house的最大收益。把环切割开来。
//      yes[i] = max{yes[i - 2], no[i - 2]} + nums[i]
//      no[i]  = max{yes[i - 1], no[i - 1]}
// Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them 
// together and thus the solution is now the maximum of:
//    Rob houses 0 to n - 2;   Rob houses 1 to n - 1.

class Solution {
public:
  int rob(vector<int>& nums) {
  	if (nums.size() == 0)  return 0;
  	int pre_max1_ = 0, pre_max2_ = 0, yes_max_ = 0, no_max_ = 0;
  	int pre_max1 = nums[0], pre_max2 = nums[0], yes_max = 0, no_max = nums[0];
  	for (int i = 1; i < nums.size(); ++i) {
  		// not rob the first house
  		yes_max_ = pre_max1_ + nums[i];
  		no_max_ = pre_max2_;
  		pre_max1_ = pre_max2_;  pre_max2_ = max(yes_max_, no_max_);
  		// rob the first house
  		if (i == 1)  continue;
  		yes_max = pre_max1 + nums[i];
  		no_max = pre_max2;
  		pre_max1 = pre_max2;  pre_max2 = max(yes_max, no_max);
  	}
  	return max(pre_max2_, no_max);
  }	
};


class Solution {
public:
  int rob(vector<int>& nums) {
  	if (nums.size() == 0)  return 0;
  	// rob the first house
  	int pre_max1 = nums[0], pre_max2 = nums[0], yes_max = 0, no_max = nums[0];
  	for (int i = 2; i < nums.size(); ++i) {
  		yes_max = pre_max1 + nums[i];
  		no_max = pre_max2;
  		pre_max1 = pre_max2;  pre_max2 = max(yes_max, no_max);
  	}
  	int max_rob = no_max;
  	// not rob the first house
  	pre_max1 = 0;  pre_max2 = 0;  yes_max = 0;  no_max = 0;
  	for (int i = 1; i < nums.size(); ++i) {
  		yes_max = pre_max1 + nums[i];
  		no_max = pre_max2;
  		pre_max1 = pre_max2;  pre_max2 = max(yes_max, no_max);
  	}
  	max_rob = max(max_rob, max(yes_max, no_max));
  	return max_rob;
  }	
};