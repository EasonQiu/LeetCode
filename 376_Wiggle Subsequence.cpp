// A sequence of numbers is called a wiggle sequence if the differences between successive 
// numbers strictly alternate between positive and negative. The first difference 
// (if one exists) may be either positive or negative. A sequence with fewer than two elements 
// is trivially a wiggle sequence.

// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are 
// alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not 
// wiggle sequences, the first because its first two differences are positive and the 
// second because its last difference is zero.

// Given a sequence of integers, return the length of the longest subsequence that is a 
// wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, 
// also zero) from the original sequence, leaving the remaining elements in their original order.

// Examples:
// Input: [1,7,4,9,2,5]
// Output: 6
// The entire sequence is a wiggle sequence.

// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2

// 解法：开两个数组pos和neg，pos表示最后一个diff是正数，neg表示最后一个diff是负数
//      pos[i] = max(neg[j] + 1 if nums[j] < nums[i]), 以nums[i]为结尾最后diff为正的最大子串长度
//      neg[i] = max(pos[j] + 1 if nums[j] > nums[i])
// 还有greedy的O(n)解法

class Solution { // dp version
public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <= 1)  return nums.size();
    vector<int> pos(nums.size(), 1), neg(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
    	for (int j = 0; j < i; ++j) {
    		if (nums[j] < nums[i])  pos[i] = max(pos[i], neg[j] + 1);
    		if (nums[j] > nums[i])  neg[i] = max(neg[i], pos[j] + 1);
    	}
    }
    return max(pos[nums.size() - 1], neg[nums.size() - 1]);
  }
};