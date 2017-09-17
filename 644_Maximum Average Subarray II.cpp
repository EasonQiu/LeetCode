// Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation:
// when length is 5, maximum average value is 10.8,
// when length is 6, maximum average value is 9.16667.
// Thus return 12.75.
// Note:
// 1 <= k <= n <= 10,000.
// Elements of the given array will be in range [-10,000, 10,000].
// The answer with the calculation error less than 10-5 will be accepted.



// 已知O(n)时间能求出max subarray sum，而且长度有特定限制的也行>= k
// 我们没法O(n)时间知道max subarray average, 因为subarray的长度不同导致max sum不一定是max average
// 但我们能O(n)时间知道max subarray average是否大于等于某个number，即所有elements都减去number之后是否max subarray average >= 0
//    因为此时subsum >= 0等价于subaverage >= number
// 而max subarray average在[min(nums), max(nums)], 所以可以用二分查找
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // find the min & max number in the array
        double left = INT_MAX, right = INT_MIN;
        for (int num : nums) {
            left = min(left, double(num));
            right = max(right, double(num));
        }
        // binary search in range
        while (right - left >= 0.00001) {
            double mid = left + (right - left) / 2;
            if (hasSubarrayLarger(nums, mid, k)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    bool hasSubarrayLarger(vector<int> &nums, double target, int k) {
        double min_presum = 0, presum = 0;
        double sum = accumulate(nums.begin(), nums.begin() + k - 1, (1 - k) * target);
        for (int i = k - 1; i < nums.size(); ++i) {
            sum += nums[i] - target;
            if (sum - min_presum > 0)  return true;
            presum += nums[i - k + 1] - target;
            min_presum = min(min_presum, presum);
        }
        return false;
    }
};