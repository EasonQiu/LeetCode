// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
// An island is surrounded by water and is formed by connecting adjacent lands horizontally 
// or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// 11110
// 11010
// 11000
// 00000
// Answer: 1

#include <iostream>
#include <vector>
using namespace std;

class Solution { // union find
 public:
	int numIslands(vector<vector<char>>& grid) {
		// corner cases
		if (grid.size() == 0 || grid[0].size() == 0)  return 0;
		// init the parent
		int count = 0;
		row = grid.size(), col = grid[0].size();
		parent = vector<vector<int> >(row, vector<int>(col));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '0')  continue;
				parent[i][j] = col * i + j;
				++count;
			}
		}
		// group the islands
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (grid[i][j] == '0')  continue;
				if (i + 1 < row && grid[i + 1][j] == '1' && find(i, j) != find(i + 1, j)) {
					unions(i, j, i + 1, j);  --count;
				}
				if (j + 1 < col && grid[i][j + 1] == '1' && find(i, j) != find(i, j + 1)) {
					unions(i, j, i, j + 1);  --count;
				}
			}
		}
		// final result
		return count;
	}

	int find(int i, int j) {
		if (parent[i][j] == col * i + j)  return parent[i][j];
		int index = parent[i][j];
		parent[i][j] = parent[index / col][index % col];
		return find(parent[i][j] / col, parent[i][j] % col);
	}

	void unions(int i1, int j1, int i2, int j2) {
		int index1 = find(i1, j1);
		parent[index1 / col][index1 % col] = find(i2, j2);
	}

 private:
 	int row, col;
 	vector<vector<int> > parent;
}; 


class Solution2 {  // dfs
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
	vector<vector<char> > grid(4, vector<char>(5, '0'));
	grid[0][0] = grid[0][1] = grid[0][2] = grid[0][3] = '1';
	grid[1][0] = grid[1][1] = grid[1][3] = '1';
	grid[2][0] = grid[2][1] = '1';

	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}