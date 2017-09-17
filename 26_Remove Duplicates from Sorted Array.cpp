// Given a sorted array, remove the duplicates in place such that each element appear 
// only once and return the new length.
// Do not allocate extra space for another array, you must do this in place with 
// constant memory.

// For example,
// Given input array nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums 
// being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1)  return nums.size();
    int left = 0, length = 1;
    for (int right = 1; right < nums.size(); ++right) {
      if (nums[right] != nums[left]) {
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