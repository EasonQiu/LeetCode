#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
        vector<vector<int> > ans(m, vector<int>(n));
        // init the first row
        ans[0][0] = grid[0][0];
        for (int j = 1; j < n; ++j)  ans[0][j] = ans[0][j - 1] + grid[0][j];
        // recursive
        for (int i = 1; i < m; ++i) {
        	ans[i][0] = ans[i - 1][0] + grid[i][0];
        	for (int j = 1; j < n; ++j) {
        		ans[i][j] = min(ans[i][j - 1], ans[i - 1][j]) + grid[i][j];
        	}
        }
        return ans[m - 1][n - 1];
	}

    int minPathSum1(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
        vector<int> rows(n, 0);
        // init the first row
        rows[0] = grid[0][0];
        for (int j = 1; j < n; ++j)  rows[j] = rows[j - 1] + grid[0][j];
        // recursive
        for (int i = 1; i < m; ++i) {
        	rows[0] += grid[i][0];
        	for (int j = 1; j < n; ++j) {
        		rows[j] = min(rows[j - 1], rows[j]) + grid[i][j];
        	}
        }
        return rows[n - 1];
    }
};

int main() {
	vector<vector<int> > grid(3, vector<int>(3));
	grid[0][0] = 1;  grid[0][1] = 3;  grid[0][2] = 1;
	grid[1][0] = 1;  grid[1][1] = 5;  grid[1][2] = 1;
	grid[2][0] = 4;  grid[2][1] = 2;  grid[2][2] = 1;

	Solution s;
	cout << s.minPathSum(grid) << endl;
	return 0;
}