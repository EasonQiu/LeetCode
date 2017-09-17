// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Note:
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.

// 2  6  4  8  10  9  15
//min 2  6  6  8  10  10  (left_max, end)
// 4  4  8  9  9  15  max (right_min, start)
//  start         end

// start: 左边第一个nums[i] > right_min
// end:   右边第一个nums[i] < left_max
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())  return 0;
        int start = 0, end = -1;
        int left_max = INT_MIN, right_min = INT_MAX;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); ++i, --j) {
            cout << left_max << " ";
            if (nums[i] < left_max)  end = i;
            if (nums[j] > right_min)  start = j;
            left_max = max(left_max, nums[i]);
            right_min = min(right_min, nums[j]);
        }
        return (start <= end) ? end - start + 1 : 0;
    }
};


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty())  return 0;
        int size = nums.size();
        int left_max[size] = {}, right_min[size] = {};
        left_max[0] = INT_MIN;  right_min[size - 1] = INT_MAX;
        for (int i = 1, j = size - 2; i < size; ++i, --j) {
            left_max[i] = max(nums[i - 1], left_max[i - 1]);
            right_min[j] = min(nums[j + 1], right_min[j + 1]);
        }
        int i = 0, j = size - 1;
        while (i <= j && nums[i] <= right_min[i])  ++i;
        while (i <= j && nums[j] >= left_max[j])  --j;
        return (i <= j) ? j - i + 1 : 0;
    }
};