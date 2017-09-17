// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

// Example 1:
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:
// Input: 9973
// Output: 9973
// Explanation: No swap.
// Note:
// The given number is in the range [0, 108]


// 找出左边第一个数，找出它右边比它大的最大的digit的最靠右的数字
class Solution {
public:
    int maximumSwap(int num) {
        string digits = to_string(num);
        // find the last position of every digit
        vector<int> last(10, -1);
        for (int i = 0; i < digits.size(); ++i) {
            last[digits[i] - '0'] = i;
        }
        // swap two digits
        for (int i = 0; i < digits.size(); ++i) {
            for (int j = 9; j > digits[i] - '0'; --j) {
                if (last[j] <= i)  continue;
                swap(digits[i], digits[last[j]]);
                return stoi(digits);
            }
        }
        return num;
    }
};