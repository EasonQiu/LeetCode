// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,

// Consider the following matrix:
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]

// Given target = 5, return true.
// Given target = 20, return false.

// 解法：从图表左下角或右上角出发，考虑对应L型数据
// 如果小于target说明竖上的一列全部小于target++j; 如果大于target说明横右的一行全部大于target--i。
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
  	if (matrix.empty())  return false;
  	int row = matrix.size(), col = matrix[0].size();
  	int i = row - 1, j = 0;
  	while (i >= 0 && j < col) {
  		if (matrix[i][j] == target)  return true;
  		(matrix[i][j] > target) ? --i : ++j;
  	}
  	return false;
  }
};
