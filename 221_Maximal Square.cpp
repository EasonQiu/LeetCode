// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing 
// only 1's and return its area.

// For example, given the following matrix:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

// "0001"
// "1101"
// "1111"
// "0111"
// "0111"
// Return 9 特别要注意这种情况！利用之前一部分的正方形！

// 解法：opt[i][j]表示以i,j为正方形右下角的最大正方形长度，计算是利用i-1, j-1推导
// For i > 0 and j > 0: 
// if matrix[i][j] = 0, P[i][j] = 0; 
// if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
  	if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
  	int row = matrix.size(), col = matrix[0].size();
  	int max_len = 0;
  	vector<vector<int> > opt(row, vector<int>(col));
  	for (int i = 0; i < row; ++i) {
  		for (int j = 0; j < col; ++j) {
  			if (matrix[i][j] == '0')  continue;
  			if (i == 0 || j == 0) {
  				opt[i][j] = 1;
  				max_len = max(max_len, opt[i][j]);
  			} else {
  				opt[i][j] = min(opt[i - 1][j - 1], min(opt[i - 1][j], opt[i][j - 1])) + 1;
  				max_len = max(max_len, opt[i][j]);
  			}
  		}
  	}
  	return max_len * max_len;
  }
};

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
  	if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
  	int row = matrix.size(), col = matrix[0].size();
  	int max_len = 0, len;
  	vector<vector<int> > opt(row, vector<int>(col));
  	for (int i = 0; i < row; ++i) {
  		for (int j = 0; j < col; ++j) {
  			if (matrix[i][j] == '0')  continue;
  			opt[i][j] = 1;
  			max_len = max(max_len, opt[i][j]);
  			// skip the corner cases
  			if (i == 0 || j == 0 || matrix[i - 1][j - 1] == '0')   continue;
  			// check the validation of two rectangles
  			for (len = 1; len <= opt[i - 1][j - 1]; ++len) {
  				if (matrix[i - len][j] == '0' || matrix[i][j - len] == '0')  break;
  			}
  			// increase the length of squares
  			opt[i][j] = --len + 1;
  			max_len = max(max_len, opt[i][j]);
  		}
  	}
  	return max_len * max_len;
  }
};

int main() {
	vector<string> rows = {"0001","1101","1111","0111","0111"};
	vector<vector<char> > matrix(rows.size(), vector<char>(rows[0].size()));
	for (int i = 0; i < rows.size(); ++i) {
		for (int j = 0; j < rows[0].size(); ++j) {
			matrix[i][j] = rows[i][j];
		}
	}

	Solution sol;
	cout << sol.maximalSquare(matrix) << endl;
}