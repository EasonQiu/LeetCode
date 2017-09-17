// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

// find the first postion whose number is larger than target
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
  	if (nums.empty())  return 0;
  	int left = 0, right = nums.size() - 1, mid;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		if (nums[mid] >= target && nums[mid - 1] < target) {
  			return mid;
  		} else if (nums[mid] >= target && nums[mid - 1] >= target) {
  			right = mid;
  		} else {
  			left = mid;
  		}
  	}
  	if (nums[left] >= target && (left == 0 || nums[left - 1] < target)) {
  		return left;
  	} else if (nums[right] >= target && nums[left] < target) {
  		return right;
  	};
  	return right + 1;
  }
};