// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 
// 10 ugly numbers.

// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int primes[3] = {2, 3, 5}, index[3] = {0, 0, 0};
		vector<int> ugly(n, INT_MAX);
		ugly[0] = 1;

		for (int i = 1; i < n; ++i) {
			// find the next smallest number
			for (int j = 0; j < 3; ++j) {
				ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
			}
			// update the index
			for (int j = 0; j < 3; ++j) {
				if (ugly[i] == ugly[index[j]] * primes[j])  ++index[j];
			}
		}

		return ugly[n - 1];
	}
};

int main() {
	Solution s;
	cout << s.nthUglyNumber(10) << endl;

	return 0;
}