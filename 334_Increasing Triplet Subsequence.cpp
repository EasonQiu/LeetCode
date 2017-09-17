// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.

// Examples:
// Given [1, 2, 3, 4, 5],
// return true.

// Given [5, 4, 3, 2, 1],
// return false.

// small表示min value你接下去要组成pair至少要大于small
// middle表示min value你接下来要组成triplet至少要大于middle
class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
  	if (nums.size() <= 2)  return false;
  	int small = INT_MAX, middle = INT_MAX;
  	for (int num : nums) {
  		if (num <= small) {
  			small = num;
  		} else if (num <= middle) {
  			middle = num;
  		} else {
  			return true;
  		}
  	}
  	return false;
  }
};

// DP, O(n^2)
class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
  	if (nums.size() <= 2)  return false;
  	int size = nums.size();
  	int smaller[size] = {};
  	for (int i = 1; i < size; ++i) {
  		for (int j = 0; j < i; ++j) {
  			if (nums[j] < nums[i]) {
  				smaller[i] = max(smaller[i], smaller[j] + 1);
  			}
  		}
  		if (smaller[i] >= 2)  return true;
  	}
  	return false;
  }
};