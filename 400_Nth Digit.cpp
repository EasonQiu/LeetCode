// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:

// Input:
// 3

// Output:
// 3

// 如果处理不好整除后的位数，用(n - 1) / len保证都指向同一个地方
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        long count = 9;
        while (len * count < n) {
            n -= len * count;
            ++len;
            count *= 10;
        }
        int num = pow(10, len - 1) + (n - 1) / len;
        n = (n - 1) % len;
        return to_string(num)[n] - '0';
    }
};