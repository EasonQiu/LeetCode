#include <iostream>
#include <vector>
using namespace std;

// binary search 有些时候找局部顶点也可以用，前提是返回任意一个局部顶点都对

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.empty())  return INT_MIN;
    if (nums.size() == 1)  return 0;
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
        return mid;
      }
      if (nums[mid] < nums[mid + 1]) {
        left = mid;
      } else {
        right = mid;
      }
    }
    if (nums[left] > nums[left + 1] && (left == 0 || nums[left] > nums[left - 1])) {
      return left;
    }
    return right;
  }
};

int main() {
  int a[] = {1,2,3,1};
  vector<int> nums(a,a+4);

  Solution s;
  cout << s.findPeakElement(nums);

  return 0;
}