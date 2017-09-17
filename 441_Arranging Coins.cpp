// You have a total of n coins that you want to form in a staircase shape, where every 
// k-th row must have exactly k coins.

// Given n, find the total number of full staircase rows that can be formed.

// n is a non-negative integer and fits within the range of a 32-bit signed integer.

// Example 1:
// n = 5
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
// Because the 3rd row is incomplete, we return 2.

// Example 2:
// n = 8
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤ ¤
// ¤ ¤
// Because the 4th row is incomplete, we return 3.


// find the max k that k * (k + 1) <= 2 * n
class Solution {
public:
  int arrangeCoins(int n) {
  	if (n <= 0)  return 0;
  	long left = 1, right = n, mid, count1, count2;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		count1 = mid * (mid + 1) / 2;
  		count2 = (mid + 1) * (mid + 2) / 2;
  		if (count1 <= n && count2 > n) {
  			return mid;
  		} else if (count1 <= n && count2 <= n) {
  			left = mid;
  		} else {
  			right = mid;
  		}
  	}
  	count1 = right * (right + 1) / 2;
  	count2 = (right + 1) * (right + 2) / 2;
  	if (count1 <= n && count2 > n)  return right;
  	return left;
  }
};