// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined 
// by its upper left corner (row1, col1) and lower right corner (row2, col2).

// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]

// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.

// opt[(r1, c1), (r2, c2)] = sum(r2, c2) - sum(r1-1, c2) - sum(r2, c1-1) + sum(r1-1, c1-1)

class NumMatrix {
 public:
  NumMatrix(vector<vector<int> > matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0)  return;
  	int row = matrix.size(), col = matrix[0].size();
  	sum = vector<vector<int> >(row + 1, vector<int>(col + 1));
  	for (int i = 0; i < row; ++i) {
  		int row_sum = 0;
  		for (int j = 0; j <col; ++j) {
  			row_sum += matrix[i][j];
  			sum[i + 1][j + 1] = sum[i][j + 1] + row_sum;
  		}
  	}
  }
    
  int sumRegion(int row1, int col1, int row2, int col2) {
  	return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
  }

 private:
 	vector<vector<int> > sum;
};