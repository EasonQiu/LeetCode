// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?

// Would this affect the run-time complexity? How and why?
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.
// The array may contain duplicates.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < nums[mid - 1])  return nums[mid];
      if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
        ++left;  --right;  continue;
      }
      if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
        return nums[left];
      } else if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return min(nums[left], nums[right]);
  }
};

int main() {
	int arr[10] = {2,3,4,5,6,7,1,1,1,2};
	vector<int> nums(arr, arr+10);

	Solution s;
	cout << s.findMin(nums) << endl;
	return 0;
}