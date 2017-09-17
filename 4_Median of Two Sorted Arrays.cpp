// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0

// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

// 常见方法：merge two sorted arrays O(m + n)
// O(log(min(m, n)))
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    int median = (size1 + size2) / 2;
    if ((size1 + size2) % 2 == 1) {
      return findKthSmallest(&nums1, &nums2, 0, size1 - 1, 0, size2 - 1, median + 1);
    } else {
      int n1 = findKthSmallest(&nums1, &nums2, 0, size1 - 1, 0, size2 - 1, median);
      int n2 = findKthSmallest(&nums1, &nums2, 0, size1 - 1, 0, size2 - 1, median + 1);
      return (n1 + n2) / (double)2;
    }
  }

  int findKthSmallest(vector<int> *nums1, vector<int> *nums2, int l1, int r1,
                      int l2, int r2, int k) {
    // base case
    if (r1 - l1 > r2 - l2)  return findKthSmallest(nums2, nums1, l2, r2, l1, r1, k);
    if (l1 > r1)  return (*nums2)[l2 + k - 1];
    if (k == 1)  return min((*nums1)[l1], (*nums2)[l2]); // ensure k / 2 >= 1
    // normal case
    int i = min(k / 2, r1 - l1 + 1);
    int j = k - i;
    int val1 = (*nums1)[l1 + i - 1], val2 = (*nums2)[l2 + j - 1];
    if (val1 < val2) {
      return findKthSmallest(nums1, nums2, l1 + i, r1, l2, l2 + j - 1, k - i);
    } else if (val1 > val2) {
      return findKthSmallest(nums1, nums2, l1, l1 + i - 1, l2 + j, r2, k - j);
    } else {
      return val1;
    }
  }
};


int main() {
	vector<int> nums1(1), nums2(1);
	nums1[0] = 1; // nums1[1] = 2;  
	nums2[0] = 1; // nums2[1] = 4;

	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}