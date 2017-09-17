// Given a positive integer n, find the least number of perfect square numbers 
// (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, 
// return 2 because 13 = 4 + 9.

// 解法：opt[i]表示数i的最小平方数的个数
//      opt[i] = min(opt[j] + 1 if i - j是平方数)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
  int numSquares(int n) {
    vector<int> opt(n + 1), squares;
    // compute all squares & init the opt
    for (int i = 1; i <= floor(sqrt(n)); ++i) {
    	squares.push_back(i * i);
    }
    // fill the array
    for (int i = 1; i <= n; ++i) {
    	opt[i] = i;
    	for (int square : squares) {
    		if (square > i)  break;
    		opt[i] = min(opt[i], opt[i - square] + 1);
    	}
    }
    // final result
    return opt[n];
  }
};

int main() {
	Solution s;
	cout << s.numSquares(13) << endl;
}