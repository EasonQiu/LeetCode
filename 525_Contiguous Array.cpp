// Given a binary array, find the maximum length of a contiguous subarray with equal number 
// of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// Note: The length of the given binary array will not exceed 50,000.


// 每次碰到0减sum，碰到1加sum。用hashmap记录某个sum第一次出现的index，当第二次出现时就表明这两个index之间的01相等。
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
  	unordered_map<int, int> dict; // <sum, first_index>
  	int sum = 0, max_len = 0;
  	dict[0] = -1;
  	for (int i = 0; i < nums.size(); ++i) {
  		nums[i] == 0 ? --sum : ++sum;
  		if (dict.find(sum) != dict.end()) {
  			max_len = max(max_len, i - dict[sum]);
  		} else {
  			dict[sum] = i;
  		}
  	}
  	return max_len;
  }
};