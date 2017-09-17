// Given an array of integers sorted in ascending order, find the starting and ending 
// position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

// 内层base case如果不是return只是break，可以只改变left right的值，到外层再去修改
// 写二分搜索的时候，注意while内外检测target满足的条件基本上是一样的，外层多一个检查left == 0。写条件时小心=号。

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty())  return vector<int>{-1, -1};
    // find the starting position
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target && nums[mid - 1] < target) {
        left = mid;
        break;
      }
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid;
      }
    }
    // set the starting position
    int start = -1;
    if (nums[left] == target) {
      start = left;
    } else if (nums[right] == target) {
      start = right;
    }
    if (start == -1) {
      return vector<int>{-1, -1};
    }
    // find the ending position
    left = start;
    right = nums.size() - 1;
    while (left + 1 < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target && nums[mid + 1] > target) {
        right = mid;
        break;
      }
      if (nums[mid] <= target) {
        left = mid;
      } else {
        right = mid;
      }
    }
    // set the ending position
    int end = start;
    if (nums[right] == target) {
      end = right;
    } else if (nums[left] == target) {
      end = left;
    }
    return vector<int>{start, end};
  }
};