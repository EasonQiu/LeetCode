// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums
// being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

// 解法：只要right的值不等于left前面那个值，就能保证不会有两个以上的重复

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2)  return nums.size();
    int left = 1, length = 2;
    for (int right = 2; right < nums.size(); ++right) {
      if (nums[right] != nums[left - 1]) {
        nums[++left] = nums[right];
        ++length;
      }
    }
    return length;
  }
};

int main() {
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	Solution sol;
	
	cout << sol.removeDuplicates(nums) << endl;
	for (int n : nums)  cout << n << " ";
  cout << endl;

	return 0;
}