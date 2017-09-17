// Given a non-empty array containing only positive integers, find if the array 
// can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:
// Input: [1, 2, 3, 5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// 解法：
//     

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() <= 1)  return false;
		// calculate the sum of numbers
		int capacity = 0;
		for (int i = 0; i < nums.size(); ++i)  capacity += nums[i];
		if (capacity % 2 == 1)  return false;
		capacity /= 2;
		// knapsack problem
		vector<vector<int> > opt(nums.size() + 1, vector<int>(capacity + 1));
		for (int i = 1; i <= nums.size(); ++i) {
			for (int j = 1; j <= capacity; ++j) {
				opt[i][j] = opt[i - 1][j];
				if (j >= nums[i - 1]) {
					opt[i][j] = max(opt[i][j], opt[i - 1][j - nums[i - 1]] + nums[i - 1]);
				}
			}
		}
		// final result
		return opt[nums.size()][capacity] == capacity;
	}
};

int main() {
	vector<int> nums = {1, 2, 5};
	Solution1 sol;
	cout << sol.canPartition(nums) << endl;

	return 0;
}