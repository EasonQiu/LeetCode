// Given an array nums, there is a sliding window of size k which is moving from 
// the very left of the array to the very right. You can only see the k numbers 
// in the window. Each time the sliding window moves right by one position.

// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Therefore, return the max sliding window as [3,3,5,5,6,7].

#include <iostream>
#include <vector>

using namespace std;

// 单调队列，队列里保存对应max的indx
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  	if (nums.empty())  return vector<int>();
  	int size = nums.size();
  	vector<int> ans(size - k + 1);
  	deque<int> queue; // index of max number
  	int ix = 0;
  	for (int i = 0; i < size; ++i) {
  		// remove numbers outside the current window
  		if (!queue.empty() && queue.front() == i - k) {
  			queue.pop_front();
  		}
  		// remove numbers inside the current window which is smaller than nums[i]
  		while (!queue.empty() && nums[queue.back()] <= nums[i]) {
  			queue.pop_back();
  		}
  		// add nums[i]
  		queue.push_back(i);
  		if (i >= k - 1) {
  			ans[ix++] = nums[queue.front()]; 
  		}
  	}
  	return ans;
  }
};

// For Example: A = [2,1,3,4,6,3,8,9,10,12,56], w=4
// 2, 1, 3, 4 | 6, 3, 8, 9 | 10, 12, 56|
// left_max[] = 2, 2, 3, 4 | 6, 6, 8, 9 | 10, 12, 56
// right_max[] = 4, 4, 4, 4 | 9, 9, 9, 9 | 56, 56, 56
// sliding_max = 4, 6, 6, 8, 9, 10, 12, 56

// 因为我们可以用O(n)的时间计算某个数之前或者之后的最大值(包括某个范围内)
// 因为以k为长度计算sub max，所以每一个window一定最多被分成左右两段
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty())  return vector<int>();
		int size = nums.size();
		// calculate the partial max after grouping k elements
		int left_max[size] = {}, right_max[size + 1] = {};
		right_max[size] = INT_MIN;
		for (int i = 0, j = size - 1; i < size; ++i, --j) {
			left_max[i] = (i % k == 0) ? nums[i] : max(left_max[i - 1], nums[i]);
			right_max[j] = (j % k == k - 1) ? nums[j] : max(right_max[j + 1], nums[j]);
		}
		// calculate the max
		vector<int> ans(size - k + 1);
		for (int i = 0; i + k <= size; ++i) {
			ans[i] = max(right_max[i], left_max[i + k - 1]);
		}
		// final result
		return ans;
	}
};

int main() {
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	Solution sol;

	vector<int> ans = sol.maxSlidingWindow(nums, 3);
	for (int n : ans)  cout << n << " ";
	cout << endl;

	return 0;
}