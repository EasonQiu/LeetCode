#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	// DP
    int uniquePaths1(int m, int n) {
        vector<int> rows(n, 1);
        for (int i = 1; i < m; ++i) {
        	for (int j = 1; j < n; ++j) {
        		rows[j] = rows[j - 1] + rows[j];
        	}
        }
        return rows[n - 1];
    }
};

int main() {
	Solution s;
	cout << s.uniquePaths(3, 4) << endl;
	return 0;
}