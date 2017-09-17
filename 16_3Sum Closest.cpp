// Given an array S of n integers, find three integers in S such that 
// the sum is closest to a given number, target. Return the sum of the 
// three integers. You may assume that each input would have exactly one solution.

// For example, given array S = {-1 2 1 -4}, and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// 解法：
// 感想：

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3)  return INT_MAX;
    int size = nums.size();
    int min_diff = INT_MAX, diff;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; ++i) {
      if (i != 0 && nums[i] == nums[i - 1])  continue;
      int low = i + 1, high = size - 1;
      while (low < high) {
        diff = nums[i] + nums[low] + nums[high] - target;
        if (abs(diff) < abs(min_diff))  min_diff = diff;
        if (diff < 0) {
          while (low < high && nums[low + 1] == nums[low])  ++low;
          ++low;
        } else if (diff > 0) {
          while (low < high && nums[high - 1] == nums[high])  --high;
          --high;
        } else {
          return target;
        }
      }
    }
    return target + min_diff;
  }
};


int main() {
	vector<int> nums = {-1, 2, 1, -4};
	Solution sol;

	cout << sol.threeSumClosest(nums, 1) << endl;

	return 0;
}