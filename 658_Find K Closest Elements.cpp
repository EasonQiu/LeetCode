// Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

// Example 1:
// Input: [1,2,3,4,5], k=4, x=3
// Output: [1,2,3,4]
// Example 2:
// Input: [1,2,3,4,5], k=4, x=-1
// Output: [1,2,3,4]
// Note:
// The value k is positive and will always be smaller than the length of the sorted array.
// Length of the given array is positive and will not exceed 104
// Absolute value of elements in the array and x will not exceed 104

// find the first start position whose abs(arr[mid] - x) <= abs(arr[mid + k] - x)
// 这边不会出现判断arr.size() - k + k的情况，因为如果mid == right肯定已经break了
// > > > = = < < < < <
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (abs(arr[mid] - x) <= abs(arr[mid + k] - x)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};