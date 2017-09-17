// Find the kth largest element in an unsorted array. 
// Note that it is the kth largest element in the sorted order, 
// not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 时间复杂度如果为 n + n/2 + n/4 + n/8 + ... = 2n

class Solution { // O(nlogn)
public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size())  return INT_MAX;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      // partition the subarray [low, high]
      int left = low;
      int right = high - 1;
      int pivot = nums[high];
      while (left <= right) {
        if (nums[left++] < pivot)  swap(nums[--left], nums[right--]);
      }
      swap(nums[left], nums[high]);
      // check the position of pivot
      if (left < k - 1) {
        low = left + 1;
      } else if (left > k - 1) {
        high = left - 1;
      } else {
        return nums[left];
      }
    }
    return INT_MAX;
  }
};

class Solution { // O(nlogn)
public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size())  return INT_MAX;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int num : nums) {
      if (q.size() == k) {
        if (num > q.top()) {
          q.pop();  q.push(num);
        }
      } else {
        q.push(num);
      }
    }
    return q.top();
  }
};

int main() {
  vector<int> nums = {3,2,1,5,6,4};

  Solution s;
  cout << s.findKthLargest(nums, 2) << endl;

  return 0;
}