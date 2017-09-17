// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.

// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 解法：先排序，然后固定第一个元素（不同），接着用2sum的方法对撞型指针搜索。
// 感想：记住移到下一个不同的字符的方法，可以在一开始就进行判断是否和前一个数重复。剪枝的重要性。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// -1, -1, -1, 0, 0, 1, 1, 2, 2, 2
//  i          i     i     i
//     low    low   low   low
// 注意排序之后，第一个值每次要取不同的值，不然会有重复的解出现。相当于实现set去重的效果
// 这里有两个剪枝的小技巧要记住
class Solution { // O(n^2), beats 98.72%
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    if (nums.size() < 3)  return vector<vector<int> >();
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    for (int i = 0; i < size - 2; ++i) {
      if (i != 0 && nums[i] == nums[i - 1])  continue; // de-duplicate
      if (nums[i] + nums[i + 1] + nums[i + 2] > 0)  break; // min sum is larger than 0
      if (nums[i] + nums[size - 2] + nums[size - 1] < 0)  continue; // max current sum is smaller than 0
      int target = -nums[i];
      int low = i + 1, high = size - 1;
      while (low < high) {
        if (nums[low] + nums[high] == target) {
          ans.push_back(vector<int>{nums[i], nums[low], nums[high]});
          while (low < high && nums[low + 1] == nums[low])  ++low;
          while (low < high && nums[high - 1] == nums[high])  --high; // 可以省
          ++low;  --high;
        } else if (nums[low] + nums[high] < target) {
          ++low;
        } else {
          --high;
        }
      }
    }
    return ans;
  }
};


int main() {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	Solution sol;

	vector<vector<int> > ans = sol.threeSum(nums);
	for (vector<int> vec : ans) {
		for (int n : vec)  cout << n << " ";
		cout << endl;
	}

	return 0;
}