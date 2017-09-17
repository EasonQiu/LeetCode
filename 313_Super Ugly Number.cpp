// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are 
// in the given prime list primes of size k. 
// For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of 
// the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

// 解法：用index数组保存每个prime所对应的当前最小的ugly number的index

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
 public:
 	int val, prime, ix;
 	Node(int val_, int prime_, int ix_) : val(val_), prime(prime_), ix(ix_) {}
};

class NodeCompare {
 public:
 	bool operator() (const Node &lhs, const Node &rhs) const {
 		return lhs.val >= rhs.val;
 	}
}

class Solution {
public:
	int nthSuperUglyNumber2(int n, vector<int>& primes) {
		if (primes.size() == 0)  return -1;
		vector<int> ugly(n, INT_MAX), index(primes.size());

		ugly[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < primes.size(); ++j) {
				ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
			}
			for (int j = 0; j < primes.size(); ++j) {
				if (ugly[i] == ugly[index[j]] * primes[j])  ++index[j];
			}
 		}

		return ugly[n - 1];
	}
};

int main() {
	vector<int> primes = {2, 7, 13, 19};
	Solution sol;
	cout << sol.nthSuperUglyNumber(12, primes) << endl;

	return 0;
}