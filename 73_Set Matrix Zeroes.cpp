// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

// click to show follow up.

// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


// 注意在赋值0的时候要从下网上赋值，因为第一行和第一列为特殊列，要最后处理
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
  	int col0 = -1, row = matrix.size(), col = matrix[0].size();
  	for (int i = 0; i < row; ++i) {
  		if (matrix[i][0] == 0)  col0 = 0;
  		for (int j = 1; j < col; ++j) {
  			if (matrix[i][j] == 0) {
  				matrix[i][0] = 0;  matrix[0][j] = 0;
  			}
  		}
  	}
  	for (int i = row - 1; i >= 0; --i) {
  		for (int j = col - 1; j >= 1; --j) {
  			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
  				matrix[i][j] = 0;
  			}
  		}
  		if (col0 == 0)  matrix[i][0] = 0;
  	}
  }
};