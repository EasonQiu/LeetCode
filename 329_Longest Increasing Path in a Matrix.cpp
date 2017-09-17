#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/#/description

// 另外一种解法，转换为graph。变成找graph中最长的path，即每次删除出度为0的点。
// http://www.allenlipeng47.com/blog/index.php/2016/01/22/longest-increasing-path-in-a-matrix/

class Solution {  // beats 91.27%
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> > cache(row, vector<int>(col, 0));
        int maxLen = 1;
        for (unsigned int i = 0; i < row; ++i) {
        	for (unsigned int j = 0; j < col; ++j) {
        		// if already in cache, it must not be the longest path
        		if (cache[i][j] != 0)  continue;
        		maxLen = max(maxLen, dfs(matrix, i, j, cache));
        	}
        }
        return maxLen;
    }

    // dfs return the max length starting from point[i][j]
    int dfs(vector<vector<int> >& matrix, int i, int j, vector<vector<int> >& cache) {
    	if (cache[i][j] != 0)  return cache[i][j];
    	cache[i][j] = 1;
    	int i2, j2;
    	for (unsigned int ix = 0; ix < 4; ++ix) {
    		i2 = i + direct[ix][0];  j2 = j + direct[ix][1];
    		if (i2 >= 0 && i2 < matrix.size() && j2 >= 0 && j2 < matrix[0].size() 
    			&& matrix[i2][j2] > matrix[i][j]) {
    			cache[i][j] = max(cache[i][j], 1 + dfs(matrix, i2, j2, cache));
    		}
    	}
    	return cache[i][j];
    }

private:
	int direct[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
};

int main() {
	vector<vector<int> > matrix(3, vector<int>(3));
	matrix[0][0] = 9;  matrix[0][1] = 9;  matrix[0][2] = 4;
	matrix[1][0] = 6;  matrix[1][1] = 6;  matrix[1][2] = 8;
	matrix[2][0] = 2;  matrix[2][1] = 1;  matrix[2][2] = 1;

	Solution s;
	cout << s.longestIncreasingPath(matrix) << endl;

	return 0;
}