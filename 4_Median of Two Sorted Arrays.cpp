#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size = nums1.size() + nums2.size();
        int k = size / 2 + 1;
        vector<int> *arr1 = &nums1, *arr2 = &nums2;
        if (size % 2 == 1) {
			return BiSearch(arr1, arr2, 0, nums1.size()-1, 0, nums2.size()-1, k);
        } else {
        	int mid1 = BiSearch(arr1, arr2, 0, nums1.size()-1, 0, nums2.size()-1, k);
        	int mid2 = BiSearch(arr1, arr2, 0, nums1.size()-1, 0, nums2.size()-1, k-1);
        	return (mid1 + mid2) / (double)2;
        }
    }

    int BiSearch(vector<int>* nums1, vector<int>* nums2, 
    			 int l1, int r1, int l2, int r2, int k) {
    	if (r1 - l1 > r2 - l2)  return BiSearch(nums2, nums1, l2, r2, l1, r1, k);
    	if (l1 > r1)  return (*nums2)[l2 + k - 1];  // nums1 comes to the end
    	if (k == 1)   return min((*nums1)[l1], (*nums2)[l2]);
    	int p1 = min(r1 - l1 + 1, k / 2);
    	int p2 = k - p1;
    	if ((*nums1)[l1 + p1 - 1] < (*nums2)[l2 + p2 - 1]) {
    		return BiSearch(nums1, nums2, l1+p1, r1, l2, l2+p2-1, k-p1);
    	} else if ((*nums1)[l1 + p1 - 1] > (*nums2)[l2 + p2 - 1]) {
    		return BiSearch(nums1, nums2, l1, l1+p1-1, l2+p2, r2, k-p2);
    	} else {
    		return (*nums1)[l1+p1-1];
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