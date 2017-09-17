#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1, i1 = m - 1, i2 = n - 1;
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] >= nums2[i2]) {
                nums1[j--] = nums1[i1--];
            } else {
                nums1[j--] = nums2[i2--];
            }
        }
        while (i1 >= 0)  nums1[j--] = nums1[i1--];
        while (i2 >= 0)  nums1[j--] = nums2[i2--];
    }
};

int main() {
    int arr1[1] = {0};
    int arr2[1] = {1};
    vector<int> nums1(arr1, arr1+1);
    vector<int> nums2(arr2, arr2+1);
    nums1.resize(3);

    Solution s;
    s.merge(nums1, 0, nums2, 1);

    return 0;
}