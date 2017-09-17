// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Write a function to determine if a given target is in the array.

// The array may contain duplicates.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool search(vector<int>& nums, int target) {
  	if (nums.empty())  return false;
  	int left = 0, right = nums.size() - 1, mid;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		if (nums[mid] == target)  return true;
  		// corner cases
  		if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
  			++left;  --right;  continue;
  		}
  		// normal three cases
  		if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
  			(nums[mid] < target) ? left = mid : right = mid;
  		} else if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
  			(nums[left] <= target && target < nums[mid]) ? right = mid : left = mid;
  		} else {
  			(nums[mid] < target && target <= nums[right]) ? left = mid : right = mid;
  		}
  	}
  	if (nums[left] == target || nums[right] == target)  return true;
  	return false;
  }
};

int main() {
  int a[] = {1,3,1,1,1};
  vector<int> nums(a,a+7);

  Solution s;
  cout << s.search(nums,3);

  return 0;
}