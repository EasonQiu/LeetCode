// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
// Now given N, how many beautiful arrangements can you construct?

// Example 1:
// Input: 2
// Output: 2
// Explanation: 

// The first beautiful arrangement is [1, 2]:

// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second beautiful arrangement is [2, 1]:

// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.


// 从N开始遍历速度更快，因为数字越大越不容易被整除
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N + 1);
        for (int i = 1; i <= N; ++i)  nums[i] = i;
        int ans = 0;
        backtrack(nums, N, ans);
        return ans;
    }
    
    void backtrack(vector<int>& nums, int i, int& ans) {
        if (i == 0) {
            ++ans;  return;
        }
        for (int j = i; j >= 1; --j) {
            swap(nums[i], nums[j]);
            if (i % nums[i] == 0 || nums[i] % i == 0)  backtrack(nums, i - 1, ans);
            swap(nums[i], nums[j]);
        }
    }
};