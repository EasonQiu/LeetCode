#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if (n == 1)  return 1;
        int num1 = 1, num2 = 2;
        for (int i = 3; i <= n; ++i) {
        	num1 = (num2 += num1) - num1;
        }
        return num2;
    }
};

int main() {
	Solution s;
	cout << s.climbStairs(4) << endl;
	return 0;
}