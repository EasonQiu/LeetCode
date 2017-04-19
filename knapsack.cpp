#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, vector<int>& w, vector<int>& v) {
	int n = w.size();
	if (capacity == 0 || n == 0)  return 0;
	vector<vector<int> > ans(n + 1, vector<int>(capacity + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= capacity; ++j) {
			ans[i][j] = ans[i - 1][j];
			if (w[i] <= j && ans[i - 1][j - w[i]] + v[i] > ans[i][j]) {
				ans[i][j] = ans[i - 1][j - w[i]] + v[i];
			}
		}
	}
	return ans[n][capacity];
}

int main() {
	int a[4] = {1,3,4,5}, b[4] = {3,8,4,7};
	vector<int> w(a, a+4), v(b, b+4);

	cout << knapsack(7, w, v) << endl;
	return 0;
}