#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size(), mid;
        while (left <= right) {
        	mid = left + (right - left) / 2;
        	if ((mid == 0) || (mid > 0 && nums[mid - 1] > nums[mid]))  return nums[mid];
        	if (nums[left] <= nums[mid] && nums[mid] >= nums[right]) {
        		left = mid + 1;
        	} else if (nums[left] >= nums[mid] && nums[mid] <= nums[right]) {
        		right = mid;
        	}
        }
        return nums[left];
    }
};

int main() {
	int arr[10] = {2,3,4,5,6,7,1,1,1,2};
	vector<int> nums(arr, arr+10);

	Solution s;
	cout << s.findMin(nums) << endl;
	return 0;
}