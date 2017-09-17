// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

// Example 1:
// Input: [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
//     After flipping, the maximum number of consecutive 1s is 4.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000
// Follow up:
// What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

// 用queue去记录所有zero的index，存到k个zero的时候update一下max_len
// 算法有点类似sliding window, 找一个substring最多包含k个0
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k = 1; // number of zeroes you can flip
        int max_len = 0;
        queue<int> zeroes; // index of zeroes
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0)  zeroes.push(r);  // extend
            if (zeroes.size() > k) {  // shrink
                l = zeroes.front() + 1;
                zeroes.pop();
            }
            max_len = max(max_len, r - l + 1);  // update
        }
        return max_len;
    }
};

// 以0为分割
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pre_len = -1, cur_len = 0;
        int max_len = 0;
        nums.push_back(0);
        for (int num : nums) {
            if (num == 0) {
                max_len = max(max_len, pre_len + 1 + cur_len);
                pre_len = cur_len;
                cur_len = 0;
            } else {
                ++cur_len;
            }
        }
        return max_len;
    }
};