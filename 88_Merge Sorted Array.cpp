#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1,pos2 = n - 1, pos3 = m + n -1;
        while (pos1 >= 0 && pos2 >= 0)
            nums1[pos3--] = (nums1[pos1] > nums2[pos2]) ? nums1[pos1--] : nums2[pos2--];
        while (pos1 >= 0)
            nums1[pos3--] = nums1[pos1--];
        while (pos2 >= 0)
            nums1[pos3--] = nums2[pos2--];
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