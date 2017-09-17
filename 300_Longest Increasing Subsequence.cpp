// Given an unsorted array of integers, find the length of longest increasing subsequence.
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

// Your algorithm should run in O(n2) complexity.
// Follow up: Could you improve it to O(n log n) time complexity?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tails is an array storing the smallest tail of all increasing subsequences with length i+1 in tails[i].
// For example, say we have nums = [4,5,6,3], then all the available increasing subsequences are:

// len = 1   :      [4], [5], [6], [3]   => tails[0] = 3
// len = 2   :      [4, 5], [5, 6]       => tails[1] = 5
// len = 3   :      [4, 5, 6]            => tails[2] = 6
// We can easily prove that tails is a increasing array. Therefore it is possible to do a binary search in tails array to find the one needs update.

// Each time we only do one of the two:

// (1) if x is larger than all tails, append it, increase the size by 1
// (2) if tails[i-1] < x <= tails[i], update tails[i]

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())  return 0;
    vector<int> tails;
    for (int val : nums) {
      int i = lower_bound(tails.begin(), tails.end(), val) - tails.begin();
      if (i == tails.size()) {
        tails.push_back(val);
      } else {
        tails[i] = val;
      }
    }
    return tails.size();
  }
};

class Solution2 {  // O(n^2) version
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> f(n, 1);
        for (int j = 0; j < n; ++j) {
        	for (int i = 0; i < j; ++i) {
        		if (nums[i] < nums[j] && f[j] < f[i] + 1)  
        			f[j] = f[i] + 1;
        	}
        	ans = max(ans, f[j]);
        }
        return ans;
    }
};

int main() {
	int arr[8] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(arr, arr+8);
	Solution s;
	cout << s.lengthOfLIS(nums) << endl;
	return 0;
}