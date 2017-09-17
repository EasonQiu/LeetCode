// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, 
// otherwise return -1.

// You may assume no duplicate exists in the array.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
  	if (nums.empty())  return -1;
  	int left = 0, right = nums.size() - 1, mid;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		if (nums[mid] == target)  return mid;
  		if (nums[left] < nums[mid] && nums[mid] < nums[right]) {
  			(nums[mid] < target) ? left = mid : right = mid;
  		} else if (nums[left] < nums[mid] && nums[mid] > nums[right]) {
  			(nums[mid] < target || target < nums[left])  ? left = mid : right = mid;
  		} else {
  			(nums[mid] < target && target <= nums[right]) ? left = mid : right = mid;
  		}
  	}
  	if (nums[left] == target) {
  		return left;
  	} else if (nums[right] == target) {
  		return right;
  	}
  	return -1;
  }
};

int main() {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> nums(a,a+7);

    Solution s;
    cout << s.search(nums,1);

    return 0;
}