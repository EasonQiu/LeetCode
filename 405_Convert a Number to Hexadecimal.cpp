// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

// Note:

// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.
// Example 1:

// Input:
// 26

// Output:
// "1a"
// Example 2:

// Input:
// -1

// Output:
// "ffffffff"

// 因为有符号负数>>补1，所以要用count统计
class Solution {
public:
  string toHex(int num) {
  	if (num == 0)  return "0";
  	char dec2hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
  											'a', 'b', 'c', 'd', 'e', 'f'};
    string ans;
    int count = 0;
    while (num && count++ < 8) {
    	ans = dec2hex[num & 0xf] + ans;
    	num >>= 4;
    }
    return ans;
  }
};