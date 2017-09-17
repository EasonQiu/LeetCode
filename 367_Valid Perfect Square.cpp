// Given a positive integer num, write a function which returns True if num is a perfect 
// square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False

#include <iostream>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
  	long left = 1, right = num / 2 + 1, mid, square;
  	while (left + 1 < right) {
  		mid = left + (right - left) / 2;
  		cout << left << " " << mid << " " << right << endl;
  		square = mid * mid;
  		if (square == num) {
  			return true;
  		} else if (square < num) {
  			left = mid;
  		} else {
  			right = mid;
  		}
  	}
  	if (left * left == num || right * right == num) {
  		return true;
  	}
  	return false;
  }
};

int main() {
	Solution sol;
	cout << sol.isPerfectSquare(808201) << endl;
}