// Given a set of distinct positive integers, find the largest subset such that 
// every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.

// Example 1:
// nums: [1,2,3]
// Result: [1,2] (of course, [1,3] will also be ok)

// Example 2:
// nums: [1,2,4,8]
// Result: [1,2,4,8]

// 解法：len[i]: 以nums[i]为最大值的最大subset长度； 
//      index[i]: 以nums[i]为最大值的最大长度subset中前一个数的index, 用来获得最优解集
//      用max_len存最大长度, max_index存最大长度的解中最后一个数的index
// 感想：碰到数组先排序，尤其是有我不知道两个数谁大的时候
//      因为最后一个值不一定存在于最优解中，所以要开个变量存储最优解的最后一个number的index

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) { // O(n^2)
  	if (nums.size() == 0)  return vector<int>();
  	sort(nums.begin(), nums.end());
  	vector<int> len(nums.size(), 1), index(nums.size());
  	int max_index = -1, max_len = -1;
  	// base case
  	index[0] = -1;
  	// fill the array
  	for (int i = 0; i < nums.size(); ++i) {
  		for (int j = 0; j < i; ++j) {
  			if (nums[i] % nums[j] == 0 && len[j] + 1 > len[i]) {
  				len[i] = len[j] + 1;  index[i] = j;
  			}
  		}
  		if (len[i] > max_len) {
  			max_len = len[i];  max_index = i;
  		}
  	}
  	// get the answer
  	vector<int> ans(max_len);
  	int j = max_index;
  	for (int i = max_len - 1; i >= 0; --i) {
  		ans[i] = nums[j];  j = index[j];
  	}
  	// final result
  	return ans;
  }
};