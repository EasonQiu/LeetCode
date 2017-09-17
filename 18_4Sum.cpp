// Given an array S of n integers, are there elements a, b, c, and d in S 
// such that a + b + c + d = target? Find all unique quadruplets in the array 
// which gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.

// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

// 解法：先排序，然后固定第一个元素（不同），接着用2sum的方法对撞型指针搜索
// 写的时候不要忘了排序！！

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4)  return vector<vector<int> >();
    int size = nums.size();
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 3; ++i) {
    	// de-duplicate & prune
      if (i != 0 && nums[i] == nums[i - 1])  continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)  break;
      if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target)  continue;
      int target1 = target - nums[i];
      // 3 Sum
      for (int j = i + 1; j < size - 2; ++j) {
      	// de-duplicate & prune
        if (j != i + 1 && nums[j] == nums[j - 1])  continue;
        if (nums[j] + nums[j + 1] + nums[j + 2] > target1)  break;
        if (nums[j] + nums[size - 2] + nums[size - 1] < target1)  continue;
        int target2 = target1 - nums[j];
        // 2 Sum
        int low = j + 1, high = size - 1;
        while (low < high) {
          if (nums[low] + nums[high] == target2) {
            ans.push_back(vector<int>{nums[i], nums[j], nums[low], nums[high]});
            while (low < high && nums[low + 1] == nums[low])  ++low;
            while (low < high && nums[high - 1] == nums[high])  --high;
            ++low;  --high;
          } else if (nums[low] + nums[high] < target2) {
            ++low;
          } else {
            --high;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	Solution sol;

	vector<vector<int> > ans = sol.fourSum(nums, 0);
	for (vector<int> vec : ans) {
		for (int n : vec)  cout << n << " ";
		cout << endl;
	}

	return 0;
}