#include <iostream>
#include <vector>
using namespace std;

// The idea is to sweep all 0s to the left and all 2s to the right, then all 1s are left in the middle.
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	// zeros points to first after 0, twos points to first before 2
    	// i is the "unknown" area that we must evaluate.
        int zeros = 0, twos = nums.size() - 1, i = 0;
        while (i <= twos) {
        	if (nums[i] == 0)  swap(nums[zeros++], nums[i++]);
        	else if (nums[i] == 2)  swap(nums[i], nums[twos--]);
        	else  ++i;
        }
    }
};

int main() {
	vector<int> nums = {1, 2, 2, 0, 1, 2, 0, 1};

	Solution s;
	s.sortColors(nums);

	for (int val : nums)  cout << val << " ";
	return 0;
}