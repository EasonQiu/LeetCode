// mplement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


// next larger permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)  return;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])  --i;
        if (i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while (nums[i] >= nums[j])  --j;
        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
        return;
    }
};