
// Given a binary array, find the maximum number of consecutive 1s in this array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty())  return 0;
        int max_len = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                ++i;  continue;
            };
            int j = i + 1;
            while (j < nums.size() && nums[j] == 1)  ++j;
            max_len = max(max_len, j - i);
            i = j + 1;
        }
        return max_len;
    }
};