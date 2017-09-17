// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing 
// only 1's and return its area.

// For example, given the following matrix:
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 6.

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
  	if (matrix.empty())  return 0;
  	int row = matrix.size(), col = matrix[0].size();
  	int max_area = 0;
  	vector<int> heights(col + 1);
  	for (int i = 0; i < row; ++i) {
  		// update the heights
  		for (int j = 0; j < col; ++j) {
  			heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
  		}
  		// calculate the max rectangle whose bottom line is row i
  		max_area = max(max_area, largestRectangle(heights));
  	}
  	return max_area;
  }

  int largestRectangle(vector<int> &heights) {
  	vector<int> stack;
  	int max_area = 0, cur_index, width;
  	for (int i = 0; i < heights.size(); ++i) {
  		while (!stack.empty() && heights[stack.back()] > heights[i]) {
  			cur_index = stack.back();  stack.pop_back();
  			width = stack.empty() ? i : i - stack.back() - 1;
  			max_area = max(max_area, heights[cur_index] * width);
  		}
  		stack.push_back(i);
  	}
  	return max_area;
  }
};