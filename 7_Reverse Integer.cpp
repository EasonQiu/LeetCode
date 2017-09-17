// Reverse digits of an integer.

// Example1: x = 123, return 321
// Example2: x = -123, return -321

// 注意c++的取余数规则：余数可以为负，负数取余数相当于整数取余数加个负号
class Solution {
public:
  int reverse(int x) {
    long res = 0;
    while (x) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
  }
};