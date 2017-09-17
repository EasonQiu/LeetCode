// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n.

// Example:
// Given n = 2, return 91. (The answer should be the total numbers 
// in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

// 解法：排列组合问题：n位不同digits的个数 = (n - 1) * A(n - 1)(9) + A(n)(9)
//      																包含0                   不包含0

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
  	if (n == 0)  return 1;
  	n = min(10, n);
    vector<int> opt(n + 1, 1), A9(10, 1);
    for (int i = 1; i <= 9; ++i)  A9[i] = A9[i - 1] * (10 - i);
    for (int i = 1; i <= n; ++i) {
    	opt[i] = opt[i - 1] + (i - 1) * A9[i - 1]; // plus zero cases
    	if (i < 10) opt[i] += A9[i]; // plus no zero cases
    }
    return opt[n];
  }
};