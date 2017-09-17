// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// For example,
// Given the following matrix:

// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].


class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
  	vector<int> ans;
  	if (matrix.empty())  return ans;
  	int i, j;
  	int row_min = 0, row_max = matrix.size() - 1;
  	int col_min = 0, col_max = matrix[0].size() - 1;
  	while (row_min <= row_max && col_min <= col_max) {
  		// right
  		for (j = col_min; j <= col_max; ++j) {
  			ans.push_back(matrix[row_min][j]);
  		}
  		++row_min;
  		// down
  		for (i = row_min; i <= row_max; ++i) {
  			ans.push_back(matrix[i][col_max]);
  		}
  		--col_max;
  		// left
  		if (row_min <= row_max) {
  			for (j = col_max; j >= col_min; --j) {
  				ans.push_back(matrix[row_max][j]);
  			}
  		}
  		--row_max;
  		// up
  		if (col_min <= col_max) {
  			for (i = row_max; i >= row_min; --i) {
  				ans.push_back(matrix[i][col_min]);
  			}
  		}
  		++col_min;
  	}
  	return ans;
  }
};