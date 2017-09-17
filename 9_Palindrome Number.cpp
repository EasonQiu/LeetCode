#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
  	if (x < 0)  return false;
  	int sum = 0, x_copy = x;
  	while (x_copy > 0) {
  		sum = sum * 10 + x_copy % 10;
  		x_copy = x_copy / 10;
  	}
  	return (sum == x);
  }
};

int main() {
	Solution sol;
	cout << sol.isPalindrome(42) << endl;

	return 0;
}