// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

// For example, given nums = [-2, 0, 1, 3], and target = 2.

// Return 2. Because there are two triplets which sums are less than 2:

// [-2, 0, 1]
// [-2, 0, 3]
// Follow up:
// Could you solve it in O(n2) runtime?

// 这种n Sum的题目，核心是sort之后如++left则意思是包含nums[left]的解不成立
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() <= 2)  return 0;
        int count = 0, size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ++i) {
            int left = i + 1, right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    count += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return count;
    }
};