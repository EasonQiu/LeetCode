// Given two arrays of length m and n with digits 0-9 representing two numbers. 
// Create the maximum number of length k <= m + n from digits of the two. 
// The relative order of the digits from the same array must be preserved. 
// Return an array of the k digits. 
// You should try to optimize your time and space complexity.

// Example 1:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// return [9, 8, 6, 5, 3]

// Example 2:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// return [6, 7, 6, 0, 4]

// Example 3:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// return [9, 8, 9]

// 一定要注意a.size() > -1会出错！因为左边是unsigned int不能和int比。会返回false！要转化成int
// max(vec1, vec2)也是可以的！

#include <iostream>
#include <vector>
using namespace std;

// [2,5,6,4,4,0]
// [7,3,8,0,6,5,7,6,2]
// 15
// corner cases: 注意merge时相等情况的处理
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> ans(k, -1);
        int low_bound = max(0, k - size2);
        int upper_bound = min(size1, k);
        for (int len = low_bound; len <= upper_bound; ++len) {
            ans = max(ans, merge(maxSubarray(nums1, len), maxSubarray(nums2, k - len)));
        }
        return ans;
    }
    
    vector<int> maxSubarray(vector<int>& nums, int len) {
        vector<int> ans(len);
        int size = nums.size();
        for (int i = 0, j = 0; i < size; ++i) { // j is size of ans
            while (j > 0 && j + size - i > len && ans[j - 1] < nums[i])  --j;
            if (j < len)  ans[j++] = nums[i];
        }
        return ans;
    }
    
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> ans(size1 + size2);
        for (int i = 0, j = 0, k = 0; i < size1 || j < size2; ++k) {
            ans[k] = (isLarger(nums1, i, nums2, j)) ? nums1[i++] : nums2[j++];
        }
        return ans;
    }
    
    bool isLarger(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;  ++j;
        }
        if (i == nums1.size())  return false;
        if (j == nums2.size())  return true;
        return nums1[i] > nums2[j];
    }
};

int main() {
	vector<int> nums1 = {6,7};
  vector<int> nums2 = {6,0,4};
  Solution sol;
  vector<int> ans = sol.maxNumber(nums1, nums2, 5);
  for (int val : ans)  cout << val << " ";
  cout << endl;
}