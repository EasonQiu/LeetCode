// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num 
// calculate the number of 1's in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
// But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount 
// in c++ or in any other language.

class Solution {
public:
  vector<int> countBits(int num) {
  	vector<int> dp(num + 1);
  	for (int i = 1; i <= num; ++i) {
  		dp[i] = dp[i >> 1] + (i & 1);
  	}
  	return dp;
 	}
};

class Solution {
public:
  vector<int> countBits(int num) {
  	vector<int> dp(num + 1);
  	int len, number, mask;
  	dp[1] = 1;
  	for (int i = 2; i <= num; ++i) {
  		// calculate the length of the binary representation
  		len = 0, number = i;
  		while (number != 0) {
  			++len;  number = number >> 1;
  		}
  		// create the mask
  		mask = 1;  mask = mask << (len - 1);  mask = ~mask;
  		// set the len-th digit to 0
  		number = i;  number = number & mask;
  		// fill the array
  		dp[i] = dp[number] + 1;
  	}
  	return dp;
  }
};