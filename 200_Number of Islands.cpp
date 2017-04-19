#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, row, column, size;
        // calculate the size of grid
        if (grid.size() != 0 && grid[0].size() != 0) {
        	row = grid.size();  column = grid[0].size();
        	size = row * column;
        } else {
        	return count;
        }
        for (int i = 0; i < row; ++i) {
        	for (int j = 0; j < column; ++j) {
        		if (grid[i][j] == '1') {
        			++count;
        			dfs(grid, i, j, row, column);
        		}
        	}
        }
        return count;
    }
private:
	void dfs(vector<vector<char> >& grid, int i, int j, int& row, int& column) {
		grid[i][j] = '0';
		int di[4] = {0,  0, 1, -1};
		int dj[4] = {1, -1, 0,  0};
		for (int k = 0; k < 4; ++k) {
			if (i + di[k] >= 0 && i + di[k] < row
			 && j + dj[k] >= 0 && j + dj[k] < column
			 && grid[i + di[k]][j + dj[k]] == '1') {
				dfs(grid, i + di[k], j + dj[k], row, column);
			}
		}
	}
};

int main() {
	vector<vector<char> > grid(4, vector<char>(5, 0));
	grid[0][0] = grid[0][1] = grid[0][2] = grid[0][3] = '1';
	grid[1][0] = grid[1][1] = grid[1][3] = '1';
	grid[2][0] = grid[2][1] = grid[2][4] = '1';

	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}