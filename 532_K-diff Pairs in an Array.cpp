// Given an array of integers and an integer k, you need to find the number of 
// unique k-diff pairs in the array. Here a k-diff pair is defined as an integer 
// pair (i, j), where i and j are both numbers in the array and their absolute 
// difference is k.

// Example 1:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	// hashmap
	int findPairs(vector<int>& nums, int k) {
		if (nums.size() <= 1 || k < 0)  return 0;
		unordered_map<int, int> map;  // <number, count>
		int count = 0;
		// init the hashmap
		for (int number : nums)  ++map[number];
		for (auto pair : map) {
			if (k == 0) {
				if (pair.second >= 2)  ++count;
			} else {
				if (map.find(pair.first + k) != map.end())  ++count;
			}
		}
		return count;
	}

	// two pointers
  int findPairs2(vector<int>& nums, int k) {
  	if (nums.size() <= 1)  return 0;
  	sort(nums.begin(), nums.end());
  	int count = 0;
  	for (int i = 0; i < nums.size() - 1; ++i) {
  		if (i > 0 && nums[i] == nums[i - 1])  continue;
  		for (int j = i + 1; j < nums.size(); ++j) {
  			if (j > i + 1 && nums[j] == nums[j - 1])  continue;
  			if (nums[j] - nums[i] == k) {
  				++count;  break;
  			}
  		}
  	}
  	return count;
  }
};

int main() {
	vector<int> nums = {3, 1, 4, 1, 5};

	Solution sol;
	cout << sol.findPairs(nums, 2) << endl;

	return 0;
}