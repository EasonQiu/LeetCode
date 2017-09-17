// Given a positive integer n, find the number of non-negative integers less than or equal to n, 
// whose binary representations do NOT contain consecutive ones.

// Example 1:
// Input: 5
// Output: 5
// Explanation: 
// Here are the non-negative integers <= 5 with their corresponding binary representations:
// 0 : 0
// 1 : 1
// 2 : 10
// 3 : 11
// 4 : 100
// 5 : 101
// Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy 
// the rule. 
// Note: 1 <= n <= 109


class Solution {
public:
  int findIntegers(int num) {
  	// init the Fibbonacci array
  	int fab[31] = {};
  	fab[0] = 1;  fab[1] = 2;
  	for (int i = 2; i < 31; ++i) {
  		fab[i] = fab[i - 1] + fab[i - 2];
  	}
  	// check 1's
  	int count = 0, pre_bit = 0;
  	for (int i = 30; i >= 0; --i) {
  		if (num & (1 << i)) {
  			count += fab[i];
  			if (pre_bit == 1)  return count;
  			pre_bit = 1;
  		} else {
  			pre_bit = 0;
  		}
  	}
  	// final result
  	return count + 1;
  }
};