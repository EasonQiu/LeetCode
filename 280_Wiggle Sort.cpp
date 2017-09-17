// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

// For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || 
                (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty())  return;
        int size = nums.size();
        auto midptr = nums.begin() + size / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid_val = *midptr;
        
        #define virtue(i)  nums[(2 * i + 1) % (size | 1)]
        int left = 0, right = size - 1, i = 0;
        while (i <= right) {
            if (virtue(i) > mid_val) {
                swap(virtue(left++), virtue(i++));
            } else if (virtue(i) < mid_val) {
                swap(virtue(right--), virtue(i));
            } else {
                ++i;
            }
        }
    }
};