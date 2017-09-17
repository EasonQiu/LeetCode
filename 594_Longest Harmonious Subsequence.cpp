// We define a harmonious array is an array where the difference between its maximum value 
// and its minimum value is exactly 1.

// Now, given an integer array, you need to find the length of its longest harmonious 
// subsequence among all its possible subsequences.

// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
// Note: The length of the input array will not exceed 20,000.


class Solution {
public:
  int findLHS(vector<int>& nums) {
  	unordered_map<int, int> dict;
  	for (int num : nums)  ++dict[num];
  	int max_len = 0;
  	for (int num : nums) {
  		if (dict.find(num - 1) != dict.end())  max_len = max(max_len, dict[num - 1] + dict[num]);
  		if (dict.find(num + 1) != dict.end())  max_len = max(max_len, dict[num + 1] + dict[num]);
  	}
  	return max_len;
  }
};