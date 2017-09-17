// Given an array of n positive integers and a positive integer s, find 
// the minimal length of a contiguous subarray of which the sum ≥ s. 
// If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

// 解法：sliding window

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int min_len = nums.size() + 1, sum = 0;
    for (int left = 0, right = 0; right < nums.size(); ++right) {
      // expand
      sum += nums[right];
      while (sum >= s) {
        min_len = min(min_len, right - left + 1);
        // shrink
        sum -= nums[left++];
      }
    }
    // final answer
    return (min_len == nums.size() + 1) ? 0 : min_len;
  }
};

int main() {
  vector<int> nums = {1,2,3,4,5};

  Solution s;
  cout << s.minSubArrayLen(16,nums) << endl;

  return 0;
}